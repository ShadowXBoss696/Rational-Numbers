#include <stdlib.h>
#include <stdio.h>

#include "Rational.h"

// Resource: https://courses.cs.vt.edu/cs2505/spring2013/Assignments/9/C_Rational.pdf

static void normalize(int Top, int Bottom, int *arr);

static int gcd(int u, int v);

static int lcm(int u, int v);

static Rational reciprocal(Rational R);

//-------------------------------------------------------------------- creator

// Creates and initializes a new Rational object.
Rational Rational_Construct(const int Numerator, const int Denominator) {

    // Handle zero
    if(Numerator == 0) {
        return (Rational) {0, 1};
    }

    if(Denominator == 0) {
        printf("Denominator can not be zero.\n");
        exit(0);
    }

    int *ptr = (int *) malloc(2 * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        // Memory has been successfully allocated

        normalize(Numerator, Denominator, ptr);
        Rational R = {ptr[0], ptr[1]};

        // Free the memory
        free(ptr);

        return R;
    }
}

//-------------------------------------------------------------------- unary fns

// Compute the arithmetic negation of R.
Rational Rational_Negate(const Rational R) {
    return Rational_Construct(-R.Top, R.Bottom);
}

// Compute the arithmetic floor of R.
int Rational_Floor(const Rational R) {
    return R.Top / R.Bottom;
}

// Compute the arithmetic ceiling of R.
int Rational_Ceiling(const Rational R) {
    // Formula: ⌈x/y⌉=⌊(x−1)/y⌋+1
    // Resource: https://math.stackexchange.com/questions/1044766/proving-floor-and-ceiling-of-a-rational-number

    return ((R.Top - 1) / R.Bottom) + 1;
}

// Round R to the nearest integer.
int Rational_Round(const Rational R) {
    // Formula: ⌊(x/y + 1/2)⌋
    // Resource: https://stackoverflow.com/questions/67944241/rounding-a-rational-number-to-the-nearest-integer-with-half-up

    const Rational half = Rational_Construct(1, 2);
    return Rational_Floor(Rational_Add(R, half));
}

//-------------------------------------------------------------------- binary fns

// Compute the sum of Left and Right.
Rational Rational_Add(const Rational Left, const Rational Right) {
    // Formula: For a/b + c/d
    // if b = c : Ans = (a + c) / d
    // else : Ans = (a * (lcm/b) + c * (lcm/d))/lcm, where lcm = LCM(b, d)

    int Top, Bottom;

    if (Left.Bottom == Right.Bottom) {
        Top = Left.Top + Right.Top;
        Bottom = Left.Bottom;
    } else {
        const int LCM = lcm(Left.Bottom, Right.Bottom);
        Top = Left.Top * (LCM / Left.Bottom) + Right.Top * (LCM / Right.Bottom);
        Bottom = LCM;
    }

    return Rational_Construct(Top, Bottom);
}

// Compute the difference of Left and Right.
Rational Rational_Subtract(const Rational Left, const Rational Right) {
    // Formula: a/b - c/d = a/b + (- c/d)

    return Rational_Add(Left, Rational_Negate(Right));
}

// Compute the product of Left and Right.
Rational Rational_Multiply(const Rational Left, const Rational Right) {
    // Formula: a/b * c/d = (a * c) / (b * d)

    int Top, Bottom;

    Top = Left.Top * Right.Top;
    Bottom = Left.Bottom * Right.Bottom;

    return Rational_Construct(Top, Bottom);
}

// Compute the quotient of Left and Right.
Rational Rational_Divide(const Rational Left, const Rational Right) {
    // Formula: (a/b) / (c/d) = (a/b) * (d/c)

    return Rational_Multiply(Left, reciprocal(Right));
}

//-------------------------------------------------------------------- relational fns

// Determine whether Left and Right are equal.
bool Rational_Equals(const Rational Left, const Rational Right) {
    return Left.Top == Right.Top && Left.Bottom == Right.Bottom;
}

// Determine whether Left and Right are not equal.
bool Rational_NotEquals(const Rational Left, const Rational Right) {
    return !Rational_Equals(Left, Right);
}

// Determine whether Left is less than Right.
bool Rational_LessThan(const Rational Left, const Rational Right) {
    if (Left.Bottom == Right.Bottom) {
        return Left.Top < Right.Top;
    } else {
        const int LCM = lcm(Left.Bottom, Right.Bottom);
        return Left.Top * (LCM / Left.Bottom) < Right.Top * (LCM / Right.Bottom);
    }
}

// Determine whether Left is less than or equal to Right.
bool Rational_LessThanOrEqual(const Rational Left, const Rational Right) {
    return Rational_Equals(Left, Right) || Rational_LessThan(Left, Right);
}

// Determine whether Left is greater than Right.
bool Rational_GreaterThan(const Rational Left, const Rational Right) {
    if (Left.Bottom == Right.Bottom) {
        return Left.Top > Right.Top;
    } else {
        const int LCM = lcm(Left.Bottom, Right.Bottom);
        return Left.Top * (LCM / Left.Bottom) > Right.Top * (LCM / Right.Bottom);
    }
}

// Determine whether Left is greater than or equal to Right.
bool Rational_GreaterThanOrEqual(const Rational Left, const Rational Right) {
    return Rational_Equals(Left, Right) || Rational_GreaterThan(Left, Right);
}

//-------------------------------------------------------------------- utility fns

// GCD of two non-negative numbers:  Euclid's algorithm.
// Credit: http://web.engr.orst.edu/~tgd/classes/533/code/lib/rational.C
static int gcd(int u, int v) {
    do {
        if (u < v) {
            int temp = u;
            u = v;
            v = temp;
        }
        u = u - v;
    } while (u);
    return v;
}

// LCM of two non-negative numbers
static int lcm(int u, int v) {
    // Formula: GCD * LCM = a * b

    return (u * v) / gcd(u, v);
}

// Normalize Rational Numbers
// Credit: http://web.engr.orst.edu/~tgd/classes/533/code/lib/rational.C
static void normalize(int Top, int Bottom, int *arr) {
    int sign = 1;

    if (Top < 0) {
        sign = -sign;
        Top = -Top;
    }

    if (Bottom < 0) {
        sign = -sign;
        Bottom = -Bottom;
    }

    // find the greatest common divisor
    int d = gcd(Top, Bottom);

    // move sign to top and divide by gcd
    arr[0] = sign * (Top / d);
    arr[1] = Bottom / d;
}

static Rational reciprocal(const Rational R) {
    return Rational_Construct(R.Bottom, R.Top);
}

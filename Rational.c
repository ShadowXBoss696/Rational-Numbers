#include <assert.h>

#include "Rational.h"

// Resource: https://courses.cs.vt.edu/cs2505/spring2013/Assignments/9/C_Rational.pdf

static void normalize(Rational *R);

static int gcd(int u, int v);

static int lcm(int u, int v);

static Rational reciprocal(Rational R);

//-------------------------------------------------------------------- creator

// Creates and initializes a new Rational object.
Rational Rational_Construct(const int Numerator, const int Denominator) {
    assert(Denominator != 0);

    Rational number;
    number.Top = Numerator;
    number.Bottom = Denominator;
    normalize(&number);
    return number;
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
int Rational_Round(Rational R) {
    // Formula: ⌊(x/y + 1/2)⌋
    // Resource: https://stackoverflow.com/questions/67944241/rounding-a-rational-number-to-the-nearest-integer-with-half-up

    const Rational half = Rational_Construct(1, 2);
    return Rational_Floor(Rational_Add(R, half));
}

//-------------------------------------------------------------------- binary fns

// Compute the sum of Left and Right.
Rational Rational_Add(Rational Left, Rational Right) {
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
Rational Rational_Subtract(Rational Left, Rational Right) {
    // Formula: a/b - c/d = a/b + (- c/d)

    return Rational_Add(Left, Rational_Negate(Right));
}

// Compute the product of Left and Right.
Rational Rational_Multiply(Rational Left, Rational Right) {
    normalize(&Left);
    normalize(&Right);

    Rational result;
    result.Top = Left.Top * Right.Top;
    result.Bottom = Left.Bottom * Right.Bottom;

    normalize(&result);
    return result;
}

// Compute the quotient of Left and Right.
Rational Rational_Divide(Rational Left, Rational Right) {
    // Formula: (a/b) / (c/d) = (a/b) * (d/c)

    return Rational_Multiply(Left, reciprocal(Right));
}

//-------------------------------------------------------------------- relational fns

// Determine whether Left and Right are equal.
bool Rational_Equals(Rational Left, Rational Right) {
    return false;
}

// Determine whether Left and Right are not equal.
bool Rational_NotEquals(Rational Left, Rational Right) {
    return false;
}

// Determine whether Left is less than Right.
bool Rational_LessThan(Rational Left, Rational Right) {
    return false;
}

// Determine whether Left is less than or equal to Right.
bool Rational_LessThanOrEqual(Rational Left, Rational Right) {
    return false;
}

// Determine whether Left is greater than Right.
bool Rational_GreaterThan(Rational Left, Rational Right) {
    return false;
}

// Determine whether Left is greater than or equal to Right.
bool Rational_GreaterThanOrEqual(Rational Left, Rational Right) {
    return false;
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
static void normalize(Rational *R) {
    int sign = 1;

    if (R->Top < 0) {
        sign = -sign;
        R->Top = -R->Top;
    }

    if (R->Bottom < 0) {
        sign = -sign;
        R->Bottom = -R->Bottom;
    }

    // make sure we are not dividing by zero
    assert(R->Bottom != 0);

    // find the greatest common divisor
    int d = gcd(R->Top, R->Bottom);

    // move sign to top and divide by gcd
    R->Top = sign * (R->Top / d);
    R->Bottom = R->Bottom / d;
}

static Rational reciprocal(const Rational R) {
    return Rational_Construct(R.Bottom, R.Top);
}

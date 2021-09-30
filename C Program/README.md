# Rational Numbers ( C Programming )

A rational number is any number Q that can be represented as a ratio of two integers, N and D, such that D is not zero.

```c
struct _Rational {
    int Top;        // numerator   (N)
    int Bottom;     // denominator (D)
};
typedef struct _Rational Rational;
```

## Quick start

### Installation

1. Download the above `Rational.h` and `Rational.c` files, and put it in your source folder.
2. Import the library into your C program, before use -
   ```c
   #include "Rational.h" 
   ```

### Declare New Rational Number

To create and initialize a new `Rational` object.

Syntax,

```c
// Constructor
Rational Rational_Construct(const int Numerator, const int Denominator);
```

### Perform Arithmetic Operations

This library includes a total of 5 arithmetic operations, namely
**Negate**, **Add**, **Subtract**, **Multiply** and **Divide**.

Syntax,

```c
// Negate (-R)
Rational Rational_Negate(const Rational R);

// Add (Left + Right)
Rational Rational_Add(const Rational Left, const Rational Right);

// Subtract (Left - Right)
Rational Rational_Subtract(const Rational Left, const Rational Right);

// Multiply (Left * Right)
Rational Rational_Multiply(const Rational Left, const Rational Right);

// Divide (Left / Right)
Rational Rational_Divide(const Rational Left, const Rational Right);
```

### Perform Relational Operations

This library includes all the 6 relational operations.

Syntax,

```c
// Equals (Left == Right)
bool Rational_Equals(const Rational Left, const Rational Right);

// Not Equals (Left <> Right)
bool Rational_NotEquals(const Rational Left, const Rational Right);

// LessThan (Left < Right)
bool Rational_LessThan(const Rational Left, const Rational Right);

// LessThanOrEqual (Left <= Right)
bool Rational_LessThanOrEqual(const Rational Left, const Rational Right);

// GreaterThan (Left > Right)
bool Rational_GreaterThan(const Rational Left, const Rational Right);

// GreaterThanOrEqual (Left >= Right)
bool Rational_GreaterThanOrEqual(const Rational Left, const Rational Right);
```

### Additional Operations

This library also includes some additional operations.

Syntax,

```c
// Floor ( ⌊R⌋ )
int Rational_Floor(const Rational R);

// Ceiling ( ⌈R⌉ )
int Rational_Ceiling(const Rational R);

// Round
int Rational_Round(const Rational R);
```

### How to Give Output

Example,

```c
#include <stdio.h>
#include "Rational.h"

int main(int argc, const char *argv[]) {
    
   // Construct
   Rational R = Rational_Construct(12, 7);
   
   // Give Output
   printf("R -> %d/%d\n", prompt, R.Top, R.Bottom);
}
```

Output,

```c
12/7
```

## Example

Note - See the `main.c` file.

main.c,

```c
#include <stdio.h>

#include "Rational.h"

void Rational_Print(char *prompt, const Rational R) {
    printf("%s -> %d/%d\n", prompt, R.Top, R.Bottom);
}

int main(int argc, const char *argv[]) {
    Rational A = Rational_Construct(7, -5);
    Rational B = Rational_Construct(12, 6);

    Rational_Print("A", A);
    Rational_Print("B", B);
    Rational_Print("-A", Rational_Negate(A));
    printf("floor(A) -> %d\n", Rational_Floor(A));
    printf("ceil(A) -> %d\n", Rational_Ceiling(A));
    printf("round(A) -> %d\n", Rational_Round(A));
    Rational_Print("A+B", Rational_Add(A, B));
    Rational_Print("A-B", Rational_Subtract(A, B));
    Rational_Print("A*B", Rational_Multiply(A, B));
    Rational_Print("A/B", Rational_Divide(A, B));
    printf("A==B -> %s\n", Rational_Equals(A, B) ? "true" : "false");
    printf("A<>B -> %s\n", Rational_NotEquals(A, B) ? "true" : "false");
    printf("A<B -> %s\n", Rational_LessThan(A, B) ? "true" : "false");
    printf("A<=B -> %s\n", Rational_LessThanOrEqual(A, B) ? "true" : "false");
    printf("A>B -> %s\n", Rational_GreaterThan(A, B) ? "true" : "false");
    printf("A>=B -> %s\n", Rational_GreaterThanOrEqual(A, B) ? "true" : "false");
}
```

Output,

```c
A -> -7/5
B -> 2/1
-A -> 7/5
floor(A) -> -1
ceil(A) -> 0
round(A) -> 0
A+B -> 3/5
A-B -> -17/5
A*B -> -14/5
A/B -> -7/10
A==B -> false
A<>B -> true
A<B -> true
A<=B -> true
A>B -> false
A>=B -> false
```

## Resources

- https://courses.cs.vt.edu/cs2505/spring2013/Assignments/9/C_Rational.pdf
- https://math.stackexchange.com/questions/1044766/proving-floor-and-ceiling-of-a-rational-number
- https://stackoverflow.com/questions/67944241/rounding-a-rational-number-to-the-nearest-integer-with-half-up
- http://web.engr.orst.edu/~tgd/classes/533/code/lib/rational.C

## License

Check [LICENSE](../LICENSE) file at the root of the project.
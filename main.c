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
}
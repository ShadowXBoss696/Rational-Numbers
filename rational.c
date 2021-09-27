#include <stdio.h>

#include "rational.h"

Rational Rational_Construct(int Numerator, int Denominator) {
    Rational r;
    r.Top = Numerator;
    r.Bottom = Denominator;
    return r;
}

void Rational_Print(const Rational number) {
    printf("%d/%d\n", number.Top, number.Bottom);
}
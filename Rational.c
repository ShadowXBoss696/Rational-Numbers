#include "Rational.h"

Rational Rational_Construct(const int Numerator, const int Denominator) {
    Rational number;
    number.Top = Numerator;
    number.Bottom = Denominator;
    return number;
}


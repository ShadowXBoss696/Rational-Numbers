#include <stdio.h>

#include "Rational.h"

int main(int argc, const char* argv[]) {
    Rational num = Rational_Construct(7, 5);
    printf("%d/%d", num.Top, num.Bottom);
}
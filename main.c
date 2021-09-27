#include "rational.h"

int main(int argc, const char* argv[]) {
    Rational num = Rational_Construct(7, 5);
    Rational_Print(num);
}
#ifndef rational_h
#define rational_h

struct _Rational {
    int Top;        // numerator
    int Bottom;     // denominator
};

typedef struct _Rational Rational;


// Creates and initializes a new Rational object.
Rational Rational_Construct(int Numerator, int Denominator);

// Prints Rational object.
void Rational_Print(const Rational number);

// Compute the sum of Left and Right.
Rational Rational_Add(const Rational Left, const Rational Right);

#endif
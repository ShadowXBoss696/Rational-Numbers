#ifndef RATIONAL_H
#define RATIONAL_H
#include <stdbool.h>

struct _Rational {
   int Top;
   int Bottom;
};
typedef struct _Rational Rational;

//-------------------------------------------------------------------- creator
/**
 *  Creates and initializes a new Rational object.
 *  Pre:
 *        Denominator != 0
 *  Returns:
 *        A Rational object X such that X.Top == Numerator
 *        and X.Bottom = Denominator.
 */
Rational Rational_Construct(int Numerator, int Denominator);

//-------------------------------------------------------------------- unary fns
/**
 *   Compute the arithmetic negation of R.
 *   Pre:
 *        R has been properly initialized.
 *   Returns:
 *        A Rational object X such that X + R = 0.
 */
Rational Rational_Negate(const Rational R);

/**
 *   Compute the arithmetic floor of R.
 *   Pre:
 *        R has been properly initialized.
 *   Returns:
 *        The largest integer N such that N <= R.
 */
int Rational_Floor(const Rational R);

/**
 *   Compute the arithmetic ceiling of R.
 *   Pre:
 *        R has been properly initialized.
 *   Returns:
 *        The smallest integer N such that N >= R.
 */
int Rational_Ceiling(const Rational R);

/**
 *   Round R to the nearest integer.
 *   Pre:
 *        R has been properly initialized.
 *   Returns:
 *        The closest integer N to R.
 */
int Rational_Round(const Rational R);

//-------------------------------------------------------------------- binary fns
/**
 *   Compute the sum of Left and Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        A Rational object X equal to Left + Right.
 */
Rational Rational_Add(const Rational Left, const Rational Right);

/**
 *   Compute the difference of Left and Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        A Rational object X equal to Left - Right.
 */
Rational Rational_Subtract(const Rational Left, const Rational Right);

/**
 *   Compute the product of Left and Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        A Rational object X equal to Left * Right.
 */
Rational Rational_Multiply(const Rational Left, const Rational Right);

/**
 *   Compute the quotient of Left and Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *        Right != 0.
 *   Returns:
 *        A Rational object X equal to Left / Right.
 */
Rational Rational_Divide(const Rational Left, const Rational Right);

//-------------------------------------------------------------------- relational fns
/**
 *   Determine whether Left and Right are equal.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left == Right, false otherwise.
 */
bool Rational_Equals(const Rational Left, const Rational Right);

/**
 *   Determine whether Left and Right are not equal.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left != Right, false otherwise.
 */
bool Rational_NotEquals(const Rational Left, const Rational Right);

/**
 *   Determine whether Left is less than Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left < Right, false otherwise.
 */
bool Rational_LessThan(const Rational Left, const Rational Right);

/**
 *   Determine whether Left is less than or equal to Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left <= Right, false otherwise.
 */
bool Rational_LessThanOrEqual(const Rational Left, const Rational Right);

/**
 *   Determine whether Left is greater than Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left > Right, false otherwise.
 */
bool Rational_GreaterThan(const Rational Left, const Rational Right);

/**
 *   Determine whether Left is greater than or equal to Right.
 *   Pre:
 *        Left and Right have been properly initialized.
 *   Returns:
 *        True if Left >= Right, false otherwise.
 */
bool Rational_GreaterThanOrEqual(const Rational Left, const Rational Right);

#endif

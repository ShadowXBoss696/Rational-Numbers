import 'type.dart';

extension RationalFunctions on Rational {
  // Compute the arithmetic floor of R.
  int get floor => numerator ~/ denominator;

  // Compute the arithmetic ceiling of R.
  int get ceiling {
    // Formula: ⌈x/y⌉=⌊(x−1)/y⌋+1
    // Resource: https://math.stackexchange.com/questions/1044766/proving-floor-and-ceiling-of-a-rational-number
    return ((numerator - 1) ~/ denominator) + 1;
  }

  // Round R to the nearest integer.
  int get round {
    // Formula: ⌊(x/y + 1/2)⌋
    // Resource: https://stackoverflow.com/questions/67944241/rounding-a-rational-number-to-the-nearest-integer-with-half-up

    final half = Rational(1, 2);
    return (this + half).floor;
  }

  // Abs or |x|
  Rational get abs => numerator >= 0 ? this : -this;
}

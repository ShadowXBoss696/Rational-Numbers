import 'type.dart';
import 'util.dart';

// return a * b, staving off overflow as much as possible by cross-cancellation
Rational times(Rational a, Rational b) {
  // reduce p1/q2 and p2/q1, then multiply, where a = p1/q1 and b = p2/q2
  var c = Rational(a.numerator, b.denominator);
  var d = Rational(b.numerator, a.denominator);
  return Rational(c.numerator * d.numerator, c.denominator * d.denominator);
}

// return a + b, staving off overflow
Rational plus(Rational a, Rational b) {
  // special cases
  if (a == Rational.zero()) return b;
  if (b == Rational.zero()) return a;

  // Find gcd of numerators and denominators
  int f = gcd(a.numerator, b.numerator);
  int g = gcd(a.denominator, b.denominator);

  // add cross-product terms for numerator
  Rational s = Rational(
      (a.numerator ~/ f) * (b.denominator ~/ g) +
          (b.numerator ~/ f) * (a.denominator ~/ g),
      lcm(a.denominator, b.denominator));

  // multiply back in
  return Rational(s.numerator * f, s.denominator);
}

// return -a
Rational negate(Rational R) => Rational(-R.numerator, R.denominator);

// return |a|

Rational reciprocal(Rational R) => Rational(R.denominator, R.numerator);

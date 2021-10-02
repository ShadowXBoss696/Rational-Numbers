import 'util.dart';
import 'operators.dart';

// Credit: https://introcs.cs.princeton.edu/java/92symbolic/Rational.java.html
class Rational implements Comparable {
  late int _num; // the numerator
  late int _den; // the denominator

  Rational(int numerator, int denominator) {
    if (denominator == 0) {
      throw Exception("denominator is zero");
    }

    // reduce fraction
    int g = gcd(numerator, denominator);
    _num = numerator ~/ g;
    _den = denominator ~/ g;

    // needed only for negative numbers
    if (_den < 0) {
      _den = -_den;
      _num = -_num;
    }
  }

  // zero
  Rational.zero() : this(0, 1);

  // return the numerator and denominator of (this)
  int get numerator => _num;

  int get denominator => _den;

  // return double precision representation of (this)
  double toDouble() => numerator / denominator;

  // return string representation of (this)
  @override
  String toString() {
    if (denominator == 1) {
      return "$numerator";
    } else {
      return "$numerator/$denominator";
    }
  }

  @override
  int compareTo(other) {
    // Rational
    if (other is Rational) {
      final lhs = numerator * other.denominator;
      final rhs = denominator * other.numerator;

      if (lhs < rhs) return -1;
      if (lhs > rhs) return 1;
      return 0;
    }

    // Number
    if (other is num) {
      return toDouble().compareTo(other);
    }

    // Else
    throw Exception("Rational and ${other.runtimeType} is not comparable");
  }

  // hashCode consistent with equals() and compareTo()
  // (better to hash the numerator and denominator and combine)
  @override
  int get hashCode => toString().hashCode;

  // Add
  Rational operator +(Rational other) => plus(this, other);

  // Negate
  Rational operator -() => negate(this);

  // Minus
  Rational operator -(Rational other) => this + (-other);

  // Multiply
  Rational operator *(Rational other) => times(this, other);

  // Divide
  Rational operator /(Rational other) => this * reciprocal(other);

  // is this Rational object equal to y?
  @override
  bool operator ==(Object other) => compareTo(other) == 0;

  // Less Than
  bool operator <(Rational other) => compareTo(other) < 0;

  // Less Than or Equal To
  bool operator <=(Rational other) => compareTo(other) <= 0;

  // Greater Than
  bool operator >(Rational other) => compareTo(other) > 0;

  // Greater Than or Equal To
  bool operator >=(Rational other) => compareTo(other) >= 0;
}

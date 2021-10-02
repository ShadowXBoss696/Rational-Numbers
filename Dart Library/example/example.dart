import 'package:rational_numbers/rational_numbers.dart';

void main() {
  Rational A = Rational(7, -5);
  Rational B = Rational(12, 6);

  print("A -> $A");
  print("B -> $B");
  print("-A -> ${-A}");
  print("floor(A) -> ${A.floor}");
  print("ceil(A) -> ${A.ceiling}");
  print("round(A) -> ${A.round}");
  print("A + B -> ${A + B}");
  print("A - B -> ${A - B}");
  print("A * B -> ${A * B}");
  print("A / B -> ${A / B}");
  print("A == B -> ${A == B}");
  print("A <> B -> ${A != B}");
  print("A < B -> ${A < B}");
  print("A <= B -> ${A <= B}");
  print("A > B -> ${A > B}");
  print("A >= B -> ${A >= B}");
}

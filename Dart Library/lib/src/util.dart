/// return gcd(|m|, |n|)
int gcd(int m, int n) {
  if (m < 0) m = -m;
  if (n < 0) n = -n;
  if (0 == n) {
    return m;
  } else {
    return gcd(n, m % n);
  }
}

/// return lcm(|m|, |n|)
int lcm(int m, int n) {
  if (m < 0) m = -m;
  if (n < 0) n = -n;
  return m * (n ~/ gcd(m, n)); // parentheses important to avoid overflow
}

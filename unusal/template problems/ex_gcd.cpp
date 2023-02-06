#include <bits/stdc++.h>

using namespace std;

long long x, y;

long long ex_gcd(long long a, long long b) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ex_gcd(b, a % b);
  long long temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b;
  cin >> a >> b;
  ex_gcd(a, b);
  x = (x % b + b) % b;
  cout << x << '\n';
  return 0;
}
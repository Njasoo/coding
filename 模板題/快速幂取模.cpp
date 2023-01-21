#include <bits/stdc++.h>

using namespace std;

long long QuickPower(long long a, long long b, long long p) {
  long long ans = 1, base = a;
  while (b > 0) {
    if (b & 1) {
      ans *= base;
      ans %= p;
    }
    base *= base;
    base %= p;
    b >>= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long a, b, p;
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=" << QuickPower(a, b, p) << '\n';
  return 0;
}
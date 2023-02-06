#include <bits/stdc++.h>

using namespace std;

long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ex_gcd(b, a % b, x, y);
  long long z = x;
  x = y;
  y = z - a / b * y;
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x, y, m, n, l;
  cin >> x >> y >> m >> n >> l;
  long long a = m - n, c = y - x;
  if (a < 0) { // gcd(a, l), l must be > 0, so we need to make sure a is also > 0. To make the equation still work, we have to let c = -c too, and we don't care c is > 0 or <= 0
    a = -a;
    c = -c;
  }
  // a * k + l * k' == c
  // a * k + l * k' == gcd(a, l), gcd(a, l) which is d, this is the equaltion I'm solving
  long long d = ex_gcd(a, l, x, y);
  if (c % d != 0) {
    cout << "Impossible" << '\n';
  } else {
    x = ((x * (c / d)) % (l / d) + (l / d)) % (l / d);
    cout << x << '\n';
  }
  return 0;
}
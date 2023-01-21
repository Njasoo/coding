#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  // 1 3 5 7 9 2 4 6 8 10
  // number of odd numbers == n / 2 (n % 2 == 0) : (n / 2 + 1) (n % 2 == 1)
  // number of even number == n / 2
  if (n % 2 == 1) {
    if (k <= n / 2 + 1) {
      cout << 2 * k - 1 << '\n';
    } else {
      k -= n / 2 + 1;
      cout << 2 * k << '\n';
    }
  } else {
    if (k <= n / 2) {
      cout << 2 * k - 1 << '\n';
    } else {
      k -= n / 2;
      cout << 2 * k << '\n';
    }
  }
  return 0;
}
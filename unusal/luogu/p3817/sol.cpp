/**
 *    author:  Njaso
 *    created: 03.06.2022 15:20:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    long long target = a[i] + a[i + 1] - x;
    if (target > 0) {
      ans += target;
      if (a[i + 1] >= target) {
        a[i + 1] -= target;
      } else {
        a[i + 1] = 0;
        target -= a[i + 1];
        a[i] -= target;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
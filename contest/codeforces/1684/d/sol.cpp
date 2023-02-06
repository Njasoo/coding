/**
 *    author:  Njaso
 *    created: 04.06.2022 00:27:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans += a[i];
      a[i] = n - i - a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
      ans += a[i];
    }
    ans -= (long long) k * (k + 1) / 2;
    cout << ans << '\n';
  }
  return 0;
}
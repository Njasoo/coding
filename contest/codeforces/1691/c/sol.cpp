/**
 *    author:  Njaso
 *    created: 10.06.2022 00:16:14
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
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
  ans -= 1LL * k * (k + 1) / 2;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
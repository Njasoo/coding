/**
 *    author:  Njaso
 *    created: 04.06.2022 18:51:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, n;
  cin >> w >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[l] + a[r] <= w) {
      --ans;
      ++l, --r;
    } else {
      if (a[l] + a[--r] <= w) { // the largest one doesn't have to be a pair, but the smallest one should be a pair
        --ans;
        ++l, --r;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
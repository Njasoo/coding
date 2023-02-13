/**
 *    author:  Njaso
 *    created: 17.07.2022 13:56:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> sum(n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    while (q--) {
      int x;
      cin >> x;
      if (sum[n - 1] < x) {
        cout << -1 << '\n';
      } else {
        int l = 0, r = n - 1;
        while (l <= r) {
          int mid = l + (r - l) / 2;
          if (sum[mid] < x) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        cout << l + 1 << '\n';
      }
    }
  }
  return 0;
}
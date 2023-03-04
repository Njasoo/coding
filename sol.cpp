#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      ans++;
    } else {
      ans--;
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
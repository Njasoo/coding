#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int mx = max(a[i], a[i + 1]);
      int mn = min(a[i], a[i + 1]);
      while (mx >= 2 * mn) {
        ++ans;
        mn = (mx - mn) / 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  map<int, int> hs;
  int cnt = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[j] % a[i] == 0) {
        ++hs[b[j] / a[i]];
        if (b[j] / a[i] >= cnt) {
          cnt = b[j] / a[i];
          ans = hs[b[j] / a[i]];
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
  return 0;
}
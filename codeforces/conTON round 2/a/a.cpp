#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    while (a.size() > b.size() && a.size() >= 2) {
      if (b[0] == '1') {
        a[1] = max(a[0], a[1]);
      } else {
        a[1] = min(a[0], a[1]);
      }
      a.erase(a.begin());
    }
    cout << (a == b ? "YES" : "NO") << '\n';
  }
  return 0;
}
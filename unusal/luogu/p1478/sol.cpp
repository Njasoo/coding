/**
 *    author:  Njaso
 *    created: 03.06.2022 21:02:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  struct node {
    int x, y;
  };
  int n, s;
  cin >> n >> s;
  vector<node> t(n);
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> t[i].x >> t[i].y;
  }
  sort(t.begin(), t.end(), [&](node &t1, node &t2) {
    return t1.y < t2.y;
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a + b >= t[i].x) {
      if (s - t[i].y >= 0) {
        s -= t[i].y;
        ++ans;
      } else {
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
/**
 *    author:  Njaso
 *    created: 04.06.2022 18:45:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  struct node {
    int x, y;
  };
  int n, m;
  cin >> n >> m;
  int c = n;
  vector<node> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i].x >> t[i].y;
  }
  sort(t.begin(), t.end(), [&](node i, node j) {
    return i.x < j.x;
  });
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (c > t[i].y) {
      ans += t[i].x * t[i].y;
      c -= t[i].y;
    } else {
      ans += c * t[i].x;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
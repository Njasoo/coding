/**
 *    author:  Njaso
 *    created: 03.06.2022 14:13:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  struct node {
    int a, b;
  };
  int n;
  cin >> n;
  vector<node> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i].a >> t[i].b;
  }
  sort(t.begin(), t.end(), [&](node &x, node &y) {
    return x.b < y.b;
  });
  int ans = 0;
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (t[i].a >= pos) {
      pos = t[i].b;
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
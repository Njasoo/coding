/**
 *    author:  Njaso
 *    created: 04.06.2022 00:22:02
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int x = 0;
  while (x < n && is_sorted(a[x].begin(), a[x].end())) {
    ++x;
  }
  if (x == n) {
    cout << 1 << " " << 1 << '\n';
    return;
  }
  vector<int> b = a[x], pos;
  sort(b.begin(), b.end());
  for (int j = 0; j < m; j++) {
    if (b[j] != a[x][j]) {
      pos.push_back(j);
    }
  }
  if (pos.size() > 2) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    swap(a[i][pos[0]], a[i][pos[1]]);
    if (!is_sorted(a[i].begin(), a[i].end())) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << pos[0] + 1 << " " << pos[1] + 1 << '\n';
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
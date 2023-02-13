/**
 *    author:  Njaso
 *    created: 05.06.2022 15:12:51
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> f(2 * n + 1, vector<char>(2 * m + 1));
  for (int i = 0; i < 2 * n + 1; i += 2) {
    for (int j = 0; j < 2 * m + 1; j += 2) {
      f[i][j] = '+';
    }
  }
  for (int i = 0; i < 2 * n + 1; i += 2) {
    for (int j = 1; j < 2 * m; j += 2) {
      f[i][j] = '-';
    }
  }
  for (int i = 1; i < 2 * n; i += 2) {
    for (int j = 0; j < 2 * m + 1; j += 2) {
      f[i][j] = '|';
    }
  }
  for (int i = 1; i < 2 * n; i += 2) {
    for (int j = 1; j < 2 * m; j += 2) {
      f[i][j] = '.';
    }
  }
  f[0][0] = f[0][1] = f[1][0] = f[1][1] = '.';
  for (int i = 0; i < 2 * n + 1; i++) {
    for (int j = 0; j < 2 * m + 1; j++) {
      cout << f[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int k = 0;
  while (tt--) {
    cout << "Case #" << ++k << ":" << '\n';
    solve();
  }
  return 0;
}
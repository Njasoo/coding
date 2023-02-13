/**
 *    author:  Njaso
 *    created: 15.06.2022 22:44:56
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<vector<char>> f(10, vector<char>(10));
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> f[i][j];
    }
  }

  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (f[i - 1][j - 1] == '#' && f[i - 1][j + 1] == '#' && f[i + 1][j - 1] == '#' && f[i + 1][j + 1] == '#') {
        cout << i << " " << j << '\n';
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}
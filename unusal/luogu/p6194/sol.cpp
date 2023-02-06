#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> g(9, vector<int>(9, 1));
  vector<vector<char>> f(9, vector<char>(9));
  auto fix1 = [&](int x, int y) {
    g[x][y] = 0;
    for (int i = x - 1; i >= 1; i--) {
      if (f[i][y] != '.') {
        break;
      }
      g[i][y] = 0;
    }
    for (int i = x + 1; i <= 8; i++) {
      if (f[i][y] != '.') {
        break;
      }
      g[i][y] = 0;
    }
    for (int j = y - 1; j >= 1; j--) {
      if (f[x][j] != '.') {
        break;
      }
      g[x][j] = 0;
    }
    for (int j = y + 1; j <= 8; j++) {
      if (f[x][j] != '.') {
        break;
      }
      g[x][j] = 0;
    }
  };
  auto fix2 = [&](int x, int y) {
    g[x][y] = 0;
    for (int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--) {
      if (f[i][j] != '.') {
        break;
      }
      g[i][j] = 0;
    }
    for (int i = x - 1, j = y + 1; i >= 1 && j <= 8; i--, j++) {
      if (f[i][j] != '.') {
        break;
      }
      g[i][j] = 0;
    }
    for (int i = x + 1, j = y - 1; i <= 8 && j >= 1; i++, j--) {
      if (f[i][j] != '.') {
        break;
      }
      g[i][j] = 0;
    }
    for (int i = x + 1, j = y + 1; i <= 8 && j <= 8; i++, j++) {
      if (f[i][j] != '.') {
        break;
      }
      g[i][j] = 0;
    }
  };
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> f[i][j];
    }
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (f[i][j] == 'R') {
        fix1(i, j);
      } else if (f[i][j] == 'B') {
        fix2(i, j);
      }
    }
  }
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cout << g[i][j];
    }
    cout << '\n';
  }
  return 0;
}
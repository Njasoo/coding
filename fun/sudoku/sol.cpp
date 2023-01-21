#include <bits/stdc++.h>

using namespace std;

int f[10][10];
bool b1[10][10], b2[10][10], b3[10][10];

void dfs(int x) {
  if (x > 81) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        cout << f[i][j] << " ";
      }
      cout << '\n';
    }
  } else {
    int row = (x - 1) / 9 + 1;
    int col = (x - 1) % 9 + 1;
    int block = (row - 1) / 3 * 3 + (col - 1) / 3 + 1;
    if (f[row][col] != 0) {
      dfs(x + 1);
    } else {
      for (int k = 1; k <= 9; k++) {
        if (!b1[row][k] && !b2[col][k] && !b3[block][k]) {
          b1[row][k] = true;
          b2[col][k] = true;
          b3[block][k] = true;
          f[row][col] = k;
          dfs(x + 1);
          f[row][col] = 0;
          b1[row][k] = false;
          b2[col][k] = false;
          b3[block][k] = false;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cin >> f[i][j];
      b1[i][f[i][j]] = true;
      b2[j][f[i][j]] = true;
      int block = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
      b3[block][f[i][j]] = true;
    }
  }
  dfs(1);
  return 0;
}
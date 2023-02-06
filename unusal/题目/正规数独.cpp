#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10;
int f[N][N]; 
bool b1[N][N], b2[N][N], b3[N][N];

void dfs(int x) {
  if (x > 81) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        printf("%d ", f[i][j]);
        if (j % 3 == 0) {
          printf("|");
        }
      }
      if (i % 3 == 0) {
        printf("\n--------------------");
      }
      printf("\n");
    }
    return;
  }
  int row = (x - 1) / 9 + 1;
  int col = (x - 1) % 9 + 1;
  int block = (row - 1) / 3 * 3 + (col - 1) / 3 + 1;
  if (f[row][col] != 0) {
    dfs(x + 1);
  } else {
    for (int k = 1; k <= 9; k++) {
      if (!b1[row][k] && !b2[col][k] && !b3[block][k]) {
        b1[row][k] = 1;
        b2[col][k] = 1;
        b3[block][k] = 1;
        f[row][col] = k;
        dfs(x + 1);
        b1[row][k] = 0;
        b2[col][k] = 0;
        b3[block][k] = 0;
        f[row][col] = 0;
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false)
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      scanf("%d", &f[i][j]);
      b1[i][f[i][j]] = 1;
      b2[j][f[i][j]] = 1;
      int block = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
      b3[block][f[i][j]] = 1;
    }
  }
  dfs(1);
  return 0;
}
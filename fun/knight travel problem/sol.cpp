/**
 *    author:  Njaso
 *    created: 05.06.2022 00:14:04
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 5;
long long ans = 0;
int f[N][N];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void dfs(int k, int x, int y) {
  if (k > N * N) {
    ans += 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%-3d", f[i][j]);
      }
      cout << '\n';
    }
    cout << "---------------" << '\n';
  } else {
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < N && yy >= 0 && yy < N && f[xx][yy] == 0) {
        f[xx][yy] = k;
        dfs(k + 1, xx, yy);
        f[xx][yy] = 0;
      }
    }
  } 
}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      f[i][j] = 1;
      dfs(2, i, j);
      f[i][j] = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}
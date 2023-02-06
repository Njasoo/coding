#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, inf = (int) 1e18;
int n, m, c;
long long s[N][N], ss[N][N], f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> f[i][j];
      s[i][j] = s[i - 1][j] + f[i][j];
    }
  }
  for (int i = 1; i <= n - c + 1; i++) {
    for (int j = 1; j <= m; j++) {
      long long cnt = s[i + c - 1][j] - s[i - 1][j];
      ss[i][j] = ss[i][j - 1] + cnt;
    }
  }
  long long ans = -inf;
  int x = 0, y = 0;
  for (int i = 1; i <= n - c + 1; i++) {
    for (int j = 1; j <= m - c + 1; j++) {
      long long cnt = ss[i][j + c - 1] - ss[i][j - 1];
      if (cnt > ans) {
        ans = cnt;
        x = i;
        y = j;
      }
    }
  }
  cout << x << " " << y << '\n';
  return 0;
}
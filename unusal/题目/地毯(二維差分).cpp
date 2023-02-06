#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++) {
      f[i][y1]++;
      f[i][y2 + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] += f[i][j - 1];
      cout << f[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int K, n;
  cin >> K >> n;
  vector<vector<int>> f(K + 1, vector<int>(n + 1));
  vector<vector<int>> isg(25, vector<int>(25, 1)); // isg[i][j] : is i greater than j
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> f[i][j];
    }
  }
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        isg[f[k][j]][f[k][i]] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (isg[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
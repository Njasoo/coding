#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e2 + 5;
const int MOD = (int) 1e6 + 7;
int n, m, a[N], g[N][N];

int dfs(int x, int k) {
  if (k == m) return 1;
  if (k > m) return 0;
  if (x > n) return 0;
  if (g[x][k]) return g[x][k];
  int ans = 0;
  for (int i = 0; i <= a[x]; i++) {
    ans = (ans + dfs(x + 1, k + i)) % MOD;
  }
  g[x][k] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << dfs(1, 0) << '\n';
  return 0;
}
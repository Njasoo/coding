/**
 *    author:  Njaso
 *    created: 10.06.2022 16:53:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int c[N], sum[2];
vector<int> p[N];

bool dfs(int u, bool col) {
  sum[c[u] = col]++;
  for (auto &v : p[u]) {
    if (c[v] != -1 && c[v] == c[u]) {
      return false;
    }
  }
  for (auto &v : p[u]) {
    if (c[v] == -1 && !dfs(v, col ^ 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  memset(c, -1, sizeof(c));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] == -1) {
      if (!dfs(i, 0)) {
        cout << "Impossible" << '\n';
        return 0;
      }
    }
    ans += min(sum[0], sum[1]);
    sum[0] = sum[1] = 0;
  }
  cout << ans << '\n';
  return 0;
}
/**
 *    author:  Njaso
 *    created: 08.06.2022 21:50:05
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int k, n, m, ans = 0, vis[N], meet[N], cow[N];
vector<int> p[N];

void dfs(int x) {
  vis[x] = true;
  ++meet[x];
  for (int i = 0; i < (int) p[x].size(); i++) {
    if (!vis[p[x][i]]) {
      dfs(p[x][i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> n >> m;
  for (int i = 1; i <= k; i++) {
    cin >> cow[i];
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    p[a].push_back(b);
  }
  for (int i = 1; i <= k; i++) {
    memset(vis, 0, sizeof(vis));
    dfs(cow[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (meet[i] == k) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
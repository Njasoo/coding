#include <bits/stdc++.h>

using namespace std;

vector<int> p[10005];
int pre[10005], len[10005];

int dfs(int x) {
  if (pre[x]) return pre[x];
  for (int i = 0; i < (int) p[x].size(); i++) {
    pre[x] = max(pre[x], dfs(p[x][i]));
  }
  pre[x] += len[x];
  return pre[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> len[i];
    int y;
    while (cin >> y) {
      if (!y) break;
      else p[y].push_back(x);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans << '\n';
  return 0;
}
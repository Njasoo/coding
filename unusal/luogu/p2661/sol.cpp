/**
 *    author:  Njaso
 *    created: 05.06.2022 20:58:10
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int n, ans = 0x3f3f3f3f;
int in[N], out[N], d[N], to[N];
bool vis[N], novis[N];

void dfs(int x, int k) {
  if (novis[to[x]]) {
    return;
  }
  vis[x] = true;
  d[x] = k;
  if (vis[to[x]]) {
    ans = min(ans, d[x] - d[to[x]] + 1);
  } else {
    dfs(to[x], k + 1);
    novis[to[x]] = true;
  }  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> to[i];
    out[i]++;
    in[to[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      dfs(i, 0);
    }
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> p[100005];
int a[100005];

void dfs(int x, int d) {
  if (a[x]) return;
  a[x] = d;
  for (int i = 0; i < (int) p[x].size(); i++) {
    dfs(p[x][i], d);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    p[v].push_back(u); // build the line backwards
  }
  for (int i = n; i >= 1; i--) {
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  return 0;
}
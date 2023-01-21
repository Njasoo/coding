#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int f[2 * N];

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  iota(f + 1, f + 1 + 2 * n, 1);
  for (int i = 1; i <= m; i++) {
    char opt;
    int p, q;
    cin >> opt >> p >> q;
    if (opt == 'F') {
      f[find(p)] = find(q);
    } else {
      f[find(p + n)] = find(q);
      f[find(q + n)] = find(p);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == f[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
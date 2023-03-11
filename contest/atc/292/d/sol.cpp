#include <bits/stdc++.h>
using namespace std;
vector<int> f, siz;
int find(int x) {
  while (f[x] != x) x = f[x] = f[f[x]];
  return x;
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  f[y] = x;
  siz[x] += siz[y];
  return true;
}
int size(int x) {
  return siz[find(x)];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m);
  f.resize(n);
  siz.resize(n, 1);
  iota(f.begin(), f.end(), 0);
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    merge(u[i], v[i]);
  }
  for (int i = 0; i < m; i++) {
    cnt[find(u[i])]++;
  }
  for (int i = 0; i < n; i++) {
    if (f[i] == i) {
      if (cnt[i] != siz[i]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 20005, M = 100005;
int f[N * 2];

struct node {
  int a, b, c;
}t[M];

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

bool cmp(node &x, node &y) {
  return x.c > y.c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  iota(f + 1, f + 1 + 2 * n, 1);
  for (int i = 1; i <= m; i++) {
    cin >> t[i].a >> t[i].b >> t[i].c;
  }
  sort(t + 1, t + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    if (find(t[i].a) == find(t[i].b)) {
      cout << t[i].c << '\n';
      return 0;
    } else {
      f[find(t[i].a + n)] = find(t[i].b);
      f[find(t[i].b + n)] = find(t[i].a);
    }
  }
  cout << 0 << '\n';
  return 0;
}   
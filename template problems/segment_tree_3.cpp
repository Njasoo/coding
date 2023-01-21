#include <bits/stdc++.h>

using namespace std;

int a[100001];
long long f[400001], v[400001];

void build(int x, int l, int r) {
  if (l == r) {
    f[x] = a[r];
    return;
  }
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  f[x] = f[x << 1] + f[x << 1 | 1];
}

void add(int x, int l, int r, int s, int e, long long k) {
  if (l == s && r == e) {
    v[x] += k;
    return;
  }
  v[x << 1] += v[x];
  v[x << 1 | 1] += v[x];
  v[x] = 0;
  int m = (l + r) >> 1;
  if (e <= m) {
    add(x << 1, l, m, s, e, k);
  } else if (s > m) {
    add(x << 1 | 1, m + 1, r, s, e, k);
  } else {
    add(x << 1, l, m, s, m, k);
    add(x << 1 | 1, m + 1, r, m + 1, e, k);
  }
  f[x] = f[x << 1] + v[x << 1] * (m - l + 1) + f[x << 1 | 1] + v[x << 1 | 1] * (r - m);
}

long long calc(int x, int l, int r, int s, int e) {
  if (l == s && r == e) {
    return f[x] + v[x] * (r - l + 1);
  }
  v[x << 1] += v[x];
  v[x << 1 | 1] += v[x];
  v[x] = 0;
  long long res = 0;
  int m = (l + r) >> 1;
  if (e <= m) {
    res = calc(x << 1, l, m, s, e);
  } else if (s > m) {
    res = calc(x << 1 | 1, m + 1, r, s, e);
  } else {
    res = calc(x << 1, l, m, s, m) + calc(x << 1 | 1, m + 1, r, m + 1, e);
  } 
  f[x] = f[x << 1] + v[x << 1] * (m - l + 1) + f[x << 1 | 1] + v[x << 1 | 1] * (r - m);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      add(1, 1, n, x, y, k);
    } else {
      int x, y;
      cin >> x >> y;
      cout << calc(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}
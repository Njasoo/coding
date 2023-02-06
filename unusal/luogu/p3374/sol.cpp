/**
 *    author:  Njaso
 *    created: 17.07.2022 12:18:04
**/
#include <bits/stdc++.h>

using namespace std;

int a[500001], f[2000001]; // 4N space

void build(int k, int l, int r) {
  if (l == r) {
    f[k] = a[l];
    return;
  }
  int m = l + (r - l) / 2;
  build(k + k, l, m);
  build(k + k + 1, m + 1, r);
  f[k] = f[k + k] + f[k + k + 1];
}

void add(int k, int l, int r, int x, int y) {
  f[k] += y;
  if (l == r) {
    return;
  }
  int m = l + (r - l) / 2;
  if (x <= m) {
    add(k + k, l, m, x, y);
  } else {
    add(k + k + 1, m + 1, r, x, y);
  }
}

int calc(int k, int l, int r, int s, int t) {
  if (l == s && r == t) {
    return f[k];
  }
  int m = l + (r - l) / 2;
  if (t <= m) {
    return calc(k + k, l, m, s, t);
  } else {
    if (s > m) {
      return calc(k + k + 1, m + 1, r, s, t);
    } else {
      return calc(k + k, l, m, s, m) + calc(k + k + 1, m + 1, r, m + 1, t);
    }
  }
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
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      add(1, 1, n, x, y);
    } else {
      cout << calc(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a[100001], p[100001], t[100001], b[100001], c[100001];
long long f[400001], v[400001];

void push_up(int x, int l, int r) {
  int m = (l + r) >> 1;
  f[x] = f[x << 1] + v[x << 1] * (m - l + 1) + f[x << 1 | 1] + v[x << 1 | 1] * (r - m);
}

void push_down(int x) {
  v[x << 1] += v[x];
  v[x << 1 | 1] += v[x];
  v[x] = 0;
}

void build(int x, int l, int r) {
  if (l == r) {
    f[x] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m + 1, r);
  push_up(x, l, r);
}

void change(int x, int l, int r, int s, int e, long long k) {
  if (l == s && r == e) {
    v[x] += k;
    return;
  }
  push_down(x);
  int m = (l + r) >> 1;
  if (e <= m) {
    change(x << 1, l, m, s, e, k);
  } else if (s > m) {
    change(x << 1 | 1, m + 1, r, s, e, k);
  } else {
    change(x << 1, l, m, s, m, k);
    change(x << 1 | 1, m + 1, r, m + 1, e, k);
  }
  push_up(x, l, r);
}

long long calc(int x, int l, int r, int s, int e) {
  if (l == s && r == e) {
    return f[x] + v[x] * (r - l + 1);
  }
  push_down(x);
  long long res = 0;
  int m = (l + r) >> 1;
  if (e <= m) {
    res = calc(x << 1, l, m, s, e);
  } else if (s > m) {
    res = calc(x << 1 | 1, m + 1, r, s, e);
  } else {
    res = calc(x << 1, l, m, s, m) + calc(x << 1 | 1, m + 1, r, m + 1, e);
  } 
  push_up(x, l, r);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> p[i];
  }
  build(1, 1, n);
  for (int i = 1; i < m; i++) {
    int s = min(p[i], p[i + 1]);
    int e = max(p[i], p[i + 1]) - 1;
    change(1, 1, n, s, e, 1);
  }
  for (int i = 1; i < n; i++) {
    cin >> t[i] >> b[i] >> c[i];
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    long long before = t[i] * calc(1, 1, n, i, i);
    long long after = b[i] * calc(1, 1, n, i, i) + c[i];
    ans += min(before, after);
  }
  cout << ans << '\n';
  return 0;
}
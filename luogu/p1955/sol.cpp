#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int f[N], num[2 * N];
struct node {
  int a, b, e;
}t[N];

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

void solve() {
  int n;
  cin >> n;
  int index = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i].a >> t[i].b >> t[i].e;
    num[index++] = t[i].a;
    num[index++] = t[i].b;
  }
  sort(num, num + index);
  int len = unique(num, num + index) - num;
  for (int i = 0; i < n; i++) {
    t[i].a = lower_bound(num, num + len, t[i].a) - num;
    t[i].b = lower_bound(num, num + len, t[i].b) - num;
  }
  sort(t, t + n, [&](node &x, node &y) {
    return x.e > y.e;
  });
  iota(f, f + len, 0);
  for (int i = 0; i < n; i++) {
    if (t[i].e == 1) {
      f[find(t[i].a)] = find(t[i].b);
    } else {
      if (find(t[i].a) == find(t[i].b)) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
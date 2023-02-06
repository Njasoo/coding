#include <bits/stdc++.h>

using namespace std;

int n, m, t[500001];

void add(int x, int k) {
  while (x <= n) {
    t[x] += k;
    x += x & -x;
  }
}

int sum(int x) {
  int ans = 0;
  while (x) {
    ans += t[x];
    x -= x & -x;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  int last = 0, now;
  for (int i = 1; i <= n; i++) {
    cin >> now;
    add(i, now - last);
    last = now;
  }
  for (int i = 1; i <= m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y, k;
      cin >> x >> y >> k;
      add(x, k);
      add(y + 1, -k);
    } else {
      int x;
      cin >> x;
      cout << sum(x) << '\n';
    }
  }
  return 0;
}
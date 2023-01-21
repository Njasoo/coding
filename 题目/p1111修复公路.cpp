#include <bits/stdc++.h>

using namespace std;

struct node {
  int x, y, t;
}t[100005];
int n, m, ans = -1;
int f[1005];
set<int> s;

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

bool cmp(node i, node j) {
  return i.t < j.t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i].x >> t[i].y >> t[i].t;
    // f[find(t[i].x)] = find(t[i].y);
    // s.insert(t[i].x), s.insert(t[i].y);
    // if (ans[x][y] == 0 && ans[y][x] == 0) {
    //   ans[x][y] = t;
    // }
    // if (s.size() == n && ans == -1) {
    //   int cnt = 0;
    //   for (int j = 1; j <= n; j++) {
    //     if (f[j] == j) {
    //       cnt++;
    //     }
    //   }
    //   if (cnt == 1) {
    //     ans = t;
    //   }
    // }
  }
  sort(t + 1, t + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    s.insert(t[i].x), s.insert(t[i].y);
    f[find(t[i].x)] = find(t[i].y);
    if (s.size() == n) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (f[j] == j) {
          cnt++;
        }
      }
      if (cnt == 1) {
        cout << t[i].t << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
  // int cnt = 0;
  // for (int i = 1; i <= n; i++) {
  //   if (f[i] == i) {
  //     cnt++;
  //   }
  // }
  // cout << ans << '\n';
  return 0;
}

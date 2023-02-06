#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 5;
const int MOD = (int) 1e6 + 7;
const int INF = (int) 1e9;
int a[N];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
// int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int L, n, M;
  cin >> L >> n >> M;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 0, r = L;
  int ans = 0;
  while (l <= r) {
    int m = (l + r) >> 1;
    int now = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] - a[now] < m) {
        cnt++;
      } else {
        now = i;
      }
    }
    if (cnt <= M) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
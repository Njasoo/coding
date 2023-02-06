#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n, H, M;
    cin >> n >> H >> M;
    int now_cnt = H * 60 + M;
    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
      int h, m;
      cin >> h >> m;
      sum[i] = h * 60 + m;
    }
    sort(sum.rbegin(), sum.rend());
    const int inf = (int) 1e9;
    int ans = inf;
    for (int i = 0; i < n; i++) {
      if (sum[i] >= now_cnt) {
        ans = min(sum[i] - now_cnt, ans);
      } else {
        ans = min(24 * 60 - (now_cnt - sum[i]), ans);
      }
    }
    cout << ans / 60 << " " << ans % 60 << '\n';
  }
  return 0;
}
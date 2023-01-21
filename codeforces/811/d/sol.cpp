#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    int m = (int) t.size();
    const int inf = (int) 1e9;
    vector<int> dp(m + 1, inf);
    vector<int> pre(m + 1);
    vector<int> used(m + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int k = 0; k < m; k++) {
      for (int i = 0; i < n; i++) {
        if (t.substr(k, s[i].size()) == s[i]) {
          for (int j = k + 1; j <= k + (int) s[i].size(); j++) {
            if (dp[k] + 1 < dp[j]) {
              dp[j] = dp[k] + 1;
              pre[j] = k;
              used[j] = i;
            }
          }
        }
      }
    }
    if (dp[m] < inf) {
      cout << dp[m] << '\n';
      int now = m;
      while (now) {
        cout << used[now] + 1 << " " << pre[now] + 1 << '\n';
        now = pre[now];
      }
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
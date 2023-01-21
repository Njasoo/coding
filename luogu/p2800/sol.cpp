#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;
const int N = 1000005;
int h[N], dp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    dp[i] = inf;
  }
  dp[n + 1] = inf;
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = min(dp[i], dp[i - 1]);
    if (i >= 2) {
      dp[i] = min(dp[i], dp[i - 2]);
    } 
    if (i >= 3) {
      dp[i] = min(dp[i], dp[i - 3]);
    }
    dp[i] += h[i];
  }
  cout << dp[n + 1] << '\n';
  return 0;
}
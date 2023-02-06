#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int dp[N], sum[N], a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        sum[i] = sum[j] + a[i];
      }                        
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << sum[i] << " \n"[i == n];
  }
  return 0;
}
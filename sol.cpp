#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
const int N = 2e5 + 5;
long long a[N], dp[N][2], x[N][2], y[N][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
      if (a[i] < s) {
        x[i][0] = a[i], y[i][0] = 0;
        x[i][1] = 0, y[i][1] = a[i];
      } else {
        x[i][0] = s, y[i][0] = a[i] - s;
        x[i][1] = a[i] - s, y[i][1] = s;
      }
    }
    dp[2][0] = a[1] * x[2][0];
    dp[2][1] = a[1] * x[2][1];
    for (int i = 3; i < n; i++) {
      dp[i][0] = min(dp[i - 1][0] + y[i - 1][0] * x[i][0], dp[i - 1][1] + y[i - 1][1] * x[i][0]);
      dp[i][1] = min(dp[i - 1][0] + y[i - 1][0] * x[i][1], dp[i - 1][1] + y[i - 1][1] * x[i][1]);
    }
    cout << min(dp[n - 1][0] + y[n - 1][0] * a[n], dp[n - 1][1] + y[n - 1][1] * a[n]) << '\n';
  }
  return 0;
}
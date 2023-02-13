/**
 *    author:  Njaso
 *    created: 03.07.2022 14:32:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const long long INF = (long long) 1e18;
  int n;
  cin >> n;
  vector<double> a(2 * n);
  double sum1 = 0;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    cnt0 += (a[i] == 0);
  }
  long long ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    ans += a[i];
  }
  if (cnt0 > n) {
    long long best = INF;
    for (int i = cnt0 - n; i <= n; i++) {
      best = min(best, abs(ans - 1000 * n + 1000 * i));
    }
    ans = best;
  }
  return 0;
}
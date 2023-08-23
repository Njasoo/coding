#include <bits/stdc++.h>

using namespace std;

// just need to calculate the sum of length of each segments

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<long long, int>> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i].first;
      x[i].second = i;
    }
    sort(x.begin(), x.end());
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + x[i].first;
    }
    vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
      ans[x[i].second] =  2 * x[i].first * (i + 1) - x[i].first * n + n - sum[i + 1] + sum[n] - sum[i + 1];
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
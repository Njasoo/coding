#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum[i] = sum[i - 1] + a;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << '\n';
  }
  return 0;
}
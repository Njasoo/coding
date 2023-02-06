#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  const int MOD = 998244353;
  array<long long, 100001> f, g;
  f[1] = 8, g[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    f[i] = f[i - 1] * 9 + g[i - 1];
    g[i] = g[i - 1] * 9 + f[i - 1];
    f[i] %= MOD;
    g[i] %= MOD;
  }
  for (int test = 1; test <= tt; test++) {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
      cout << 9 << '\n';
    } else {
      cout << f[n] << '\n';
    }
  }
  return 0;
}
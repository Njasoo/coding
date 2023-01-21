/**
 *    author:  Njaso
 *    created: 04.06.2022 17:20:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<long double>> f(n, vector<long double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> f[i][j];
    }
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  auto reverse_number = [&]() {
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (order[i] > order[j]) {
          ++ans;
        }
      }
    }
    return ans;
  };
  auto factorial = [&](int x) {
    int ans = 1;
    for (int i = 1; i <= x; i++) {
      ans *= i;
    }
    return ans;
  };
  long double final_ans = 0;
  for (int k = 0; k < factorial(n); k++) {
    long double cnt = 1;
    next_permutation(order.begin(), order.end());
    for (int i = 0; i < n; i++) {
      cnt *= f[i][order[i]];
    }
    if (reverse_number() % 2 == 1) {
      cnt *= -1;
    }
    final_ans += cnt;
  }
  cout << fixed << setprecision(17) << final_ans << '\n';
  return 0;
}
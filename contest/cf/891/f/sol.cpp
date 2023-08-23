#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    auto check = [&](long long x) -> bool {
      if (x < 0) return false;
      long long sq = (long long) sqrt(x);
      return sq * sq == x;
    };
    int q;
    cin >> q;
    while (q--) {
      long long x, y;
      cin >> x >> y;
      if (!check(x * x - 4 * y)) {
        cout << "0 ";
        continue;
      }
      long long sol1 = x + (long long) sqrt(x * x - 4 * y);
      if (sol1 % 2) {
        cout << "0 ";
        continue;
      }
      sol1 /= 2;
      long long sol2 = x - sol1;
      if (sol1 == sol2) {
        cout << cnt[sol1] * (cnt[sol1] - 1) / 2 << " "; // nC2
      } else {
        cout << cnt[sol1] * cnt[sol2] << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
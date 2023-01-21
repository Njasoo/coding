#include <bits/stdc++.h>

using namespace std;

int a[100005], b[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + 1 + m);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto it1 = lower_bound(a + 1, a + 1 + m, b[i]), it2 = it1;
    if (it1 != a + 1) {
      --it2;
    }
    ans += min(abs(b[i] - *it1), abs(b[i] - *it2));
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  long long now = 1, ans = 0;
  for (int i = 1; i <= m; i++) {
    long long a;
    cin >> a;
    if (now <= a) {
      ans += a - now;
    } else {
      ans += n - (now - a);
    }
    now = a;
  }
  cout << ans << '\n';
  return 0;
}
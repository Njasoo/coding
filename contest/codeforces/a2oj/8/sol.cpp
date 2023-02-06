#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      if (i * i + j == n && i + j * j == m) {
        ++ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int a = i, b = n - i;
    int cnta = 0, cntb = 0;
    for (int j = 1; j * j <= a; j++) {
      if (a % j == 0) {
        cnta++;
        if (j != a / j) cnta++;
      }
    }
    for (int j = 1; j * j <= b; j++) {
      if (b % j == 0) {
        cntb++;
        if (j != b / j) cntb++;
      }
    }
    ans += 1LL * cnta * cntb;
  }
  cout << ans << '\n';
  return 0;
}
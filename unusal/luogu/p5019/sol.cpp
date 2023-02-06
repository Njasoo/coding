/**
 *    author:  Njaso
 *    created: 04.06.2022 17:36:27
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N];

int solve(int l, int r) {
  int mn = *min_element(a + l, a + 1 + r);
  int ans = mn;
  for (int i = l; i <= r; i++) {
    a[i] -= mn;
  }
  bool check = true;
  for (int i = l; i <= r; i++) {
    if (a[i] != 0) {
      check = false;
      break;
    }
  }
  if (check) {
    return ans;
  }
  int pl = 0, pr = 0;
  for (int i = l; i <= r; i++) {
    if (pl == 0 && a[i] != 0) {
      pl = i;
    }
    if (pl != 0 && pr == 0 && a[i] == 0) {
      pr = i - 1;
    }
    if (pl != 0 && pr == 0 && a[i] != 0 && i == r) {
      pr = r;
    }
    if (pl != 0 && pr != 0) {
      ans += solve(pl, pr);
      pl = 0;
      pr = 0;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << solve(1, n) << '\n';
  return 0;
}
/**
 *    author:  Njaso
 *    created: 15.06.2022 22:34:46
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  int len = unique(a.begin(), a.end()) - a.begin();
  
  cout << ((n - len) % 2 ? len - 1 : len) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}
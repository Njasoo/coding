/**
 *    author:  Njaso
 *    created: 15.06.2022 22:29:25
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  
  int mark = a[0];
  sort(a.rbegin(), a.rend());

  for (int i = 0; i < 4; i++) {
    if (mark == a[i]) {
      cout << i << '\n';
      return;
    }
  }

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
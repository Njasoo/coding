/**
 *    author:  Njaso
 *    created: 15.06.2022 23:00:28
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> cnt(10), v;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a %= 10;
    if (cnt[a] < 3) {
      v.push_back(a);
      cnt[a]++;
    }
  }

  int t = v.size();
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t; j++) {
      for (int k = 0; k < t; k++) {
        if ((v[i] + v[j] + v[k]) % 10 == 3 && i != j && j != k && i != k) {
          cout << "YES" << '\n';
          return;
        }
      }
    }
  }
                             
  cout << "NO" << '\n';

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
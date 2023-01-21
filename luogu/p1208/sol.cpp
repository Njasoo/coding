/**
 *    author:  Njaso
 *    created: 04.06.2022 18:42:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int c = n;
  vector<pair<int, int>> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i].first >> t[i].second;
  }
  sort(t.begin(), t.end(), [&](pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (c > t[i].second) {
      ans += t[i].first * t[i].second;
      c -= t[i].second;
    } else {
      ans += c * t[i].first;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
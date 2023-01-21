/**
 *    author:  Njaso
 *    created: 03.06.2022 14:32:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    auto it = min_element(a.begin(), a.end());
    int temp = *it;
    a.erase(it);
    auto it2 = min_element(a.begin(), a.end());
    *it2 += temp;
    ans += *it2;
  }
  cout << ans << '\n';
  return 0;
}
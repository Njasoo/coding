/**
 *    author:  Njaso
 *    created: 04.06.2022 19:22:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);            
  int n;
  cin >> n;
  vector<int> h(n);
  auto waste = [&](int x, int y) {
    return (h[x] - h[y]) * (h[x] - h[y]);
  };
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  long long ans = h.back() * h.back();
  int l = 0, r = n - 1;
  while (l < r) {
    ans += waste(l, r);
    --r;
    ans += waste(l, r);
    ++l;
  }
  cout << ans << '\n';
  return 0;
}
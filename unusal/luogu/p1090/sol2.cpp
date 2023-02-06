/**
 *    author:  Njaso
 *    created: 03.06.2022 14:54:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e9;
  int n;
  cin >> n;
  vector<int> a(n), b(n, inf);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int i = 0, j = 0, ans = 0, index = 0;
  for (int k = 0; k < n - 1; k++) {
    int w = (a[i] < b[j] ? a[i++] : b[j++]);
    w += (a[i] < b[j] ? a[i++] : b[j++]);
    b[index++] = w;
    ans += w;
  }
  cout << ans << '\n';
  return 0;
}
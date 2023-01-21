/**
 *    author:  Njaso
 *    created: 03.07.2022 15:18:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << 0 << '\n';
    return 0;
  }

  return 0;
}
/**
 *    author:  Njaso
 *    created: 11.06.2022 00:10:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a, b, c;
  a = b = c = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a += x; b += y; c += z;
  }
  if (a == b && b == c && a == 0) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
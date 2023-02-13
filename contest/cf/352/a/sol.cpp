/**
 *    author:  Njaso
 *    created: 03.07.2022 13:12:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int c0 = 0, c5 = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 0) {
      c0++;
    } else {
      c5++;
    }
  }
  if (c0 == 0) {
    cout << -1 << '\n';
    return 0;
  }
  if (c5 < 9) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < c5 / 9; i++) {
    cout << "555555555";
  }
  for (int i = 0; i < c0; i++) {
    cout << 0;
  }
  cout << '\n';
  return 0;
}
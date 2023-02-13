/**
 *    author:  Njaso
 *    created: 11.06.2022 13:01:27
**/
#include <bits/stdc++.h>

using namespace std;

int f[5][5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> f[i][j];
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      int cnt = f[i][j] + f[i - 1][j] + f[i + 1][j] + f[i][j - 1] + f[i][j + 1];
      cout << (cnt % 2 ? 0 : 1);
    }
    cout << '\n';
  }
  return 0;
}
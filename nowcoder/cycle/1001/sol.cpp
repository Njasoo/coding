/**
 *    author:  Njaso
 *    created: 08.06.2022 23:52:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
      if (i <= n) {
        for (int j = 1; j <= n - i; j++) {
          cout << " ";
        }
        for (int j = 1; j <= 2 * (i - 1) + 1; j++) {
          cout << "*";
        }
        cout << '\n';
      } else {
        for (int j = 1; j <= i - n; j++) {
          cout << " ";
        }
        for (int j = 1; j <= 2 * (2 * n - i - 1) + 1; j++) {
          cout << "*";
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
/**
 *    author:  Njaso
 *    created: 09.06.2022 00:15:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char ch;
  cin >> ch;
  for (char c = 'A'; c <= ch; c++) {
    for (char cj = 'A'; cj <= ch; cj++) {
      cout << " ";
    }
    for (char cj = 'A'; cj <= 2 * (c - 1) + 1; cj++) {
      cout << cj;
    }
    cout << '\n';
  }
  return 0;
}
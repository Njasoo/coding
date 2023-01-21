/**
 *    author:  Njaso
 *    created: 11.06.2022 00:17:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '.') {
      cout << 0;
    }
    if (s[i] == '-' && s[i + 1] == '.') {
      cout << 1;
      i++;
    }
    if (s[i] == '-' && s[i + 1] == '-') {
      cout << 2;
      i++;
    }
  }
  cout << '\n';
  return 0;
}
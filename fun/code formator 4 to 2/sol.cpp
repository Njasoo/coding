/**
 *    author:  Njaso
 *    created: 23.06.2022 18:56:41
**/
#include <bits/stdc++.h>

using namespace std;

void solve(string str) {
  int cnt = 0;
  for (int i = 0; i < (int) str.size(); i++) {
    if (str[i] == ' ') {
      ++cnt;
    } else {
      break;
    }
  }
  str = str.substr(cnt / 2);
  cout << str << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  string str;
  while (getline(cin, str)) {
    solve(str);
  }
  return 0;
}
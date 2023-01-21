/**
 *    author:  Njaso
 *    created: 03.06.2022 20:55:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  int target = s.size() - k;
  if (target == 0) {
    cout << 0 << '\n';
    return 0;
  }
  while ((int) s.size() > target) {
    bool ok = false;
    for (int i = 0; i < (int) s.size() - 1; i++) {
      if (s[i] > s[i + 1]) {
        s.erase(s.begin() + i);
        ok = true;
        i--;
        break;
      }
    }
    if (!ok) {
      auto it = max_element(s.begin(), s.end());
      s.erase(it);
    }
  }
  bool done = false;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != '0') {
      done = true;
    }
    if (!done && s[i] == '0') {
      s.erase(s.begin() + i);
      i--;
    }
  }
  if (s.size() == 0) {
    cout << 0 << '\n';
  } else {
    cout << s << '\n';
  }
  return 0;
}
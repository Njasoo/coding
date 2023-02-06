#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  s += "  ";
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (s[i + 1] == '4') { 
        if (s[i + 2] == '4') {
          i = i + 2;
          if (i > n) {
            break;
          }
        } else {
          i = i + 1;
          if (i > n) {
            break;
          }
        }
      }
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
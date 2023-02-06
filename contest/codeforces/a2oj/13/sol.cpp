#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if (s.find("1111111") != string::npos || s.find("0000000") != string::npos) {
    cout << "YES" << '\n';
    return 0;
  }
  cout << "NO" << '\n';
  return 0;
}
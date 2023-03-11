#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  for (auto &c : s) {
    if (c >= 'a' && c <= 'z') {
      c -= 32;
    }
  }
  cout << s << '\n';
  return 0;
}
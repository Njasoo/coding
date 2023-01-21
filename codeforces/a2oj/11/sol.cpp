#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  string s;
  cin >> s;
  map<char, int> hs;
  for (int i = 0; i < (int) s.size(); i++) {
    ++hs[s[i]];
  }
  string one = "";
  for (auto& x : hs) {
    if (x.second % k != 0) {
      cout << -1 << '\n';
      return 0;
    } else {
      one += string(x.second / k, x.first);
    }
  }
  for (int i = 0; i < k; i++) {
    cout << one;
  }
  cout << '\n';
  return 0;
}
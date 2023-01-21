#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s = "";
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    s += ch;
  }
  string t = "";
  while (!s.empty()) {
    if (s[0] < s.back()) {
      t += s[0];
      s.erase(s.begin());
    } else if (s[0] > s.back()) {
      s.erase(s.end() - 1);
    } else {
      int l = 0, r = (int) s.size() - 1;
      while (s[l] == s[r] && l < r) {
        ++l, --r;
      }
      if (s[l] < s[r]) {
        t += s[0];
        s.erase(s.begin());
      } else {
        t += s.back();
        s.erase(s.end() - 1);
      }
    }
  }
  cout << t << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<string, int> hs;
  vector<int> yes(n + 1, 1);
  for (int i = 1; i <= (int) s.size(); i++) {
    for (int j = 0; j <= (int) s.size() - i; j++) {
      string temp = s.substr(j, i);
      hs[temp]++;
      if (hs[temp] > 1) {
        yes[i] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (yes[i]) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}
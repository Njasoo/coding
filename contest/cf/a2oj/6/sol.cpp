#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<string, int> hs;
  string ans = "";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (++hs[s] > cnt) {
      cnt = hs[s];
      ans = s;
    }
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> f(n);
  map<string, pair<int, int>> hs; // (cnt, index)
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    hs[f[i]].first++;
    hs[f[i]].second = i;
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (hs.find(s) != hs.end()) {
      cout << hs[s].first << '\n';
      cout << f[hs[s].second] << '\n';
    }
  }
  return 0;
}
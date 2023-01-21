/**
 *    author:  Njaso
 *    created: 15.06.2022 22:47:47
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  unordered_map<string, bool> hs;

  string s;
  int x;
  cin >> s >> x;
  
  int hh, mm;
  char ch;
  stringstream str(s);
  str >> hh >> ch >> mm;

  int start = hh * 60 + mm;
  int ans = 0;

  for (int i = start; ; i += x) {
    long long temp = i;
    temp = temp - (temp / 1440) * 1440;

    int x_hh = temp / 60;
    int x_mm = temp % 60;

    string s_hh = to_string(x_hh);
    string s_mm = to_string(x_mm);

    if (s_hh.size() < 2) {
      s_hh = "0" + s_hh;
    }
    if (s_mm.size() < 2) {
      s_mm = "0" + s_mm;
    }

    string tim = s_hh + ":" + s_mm;
    string rtim(tim.rbegin(), tim.rend());

    if (tim == rtim && !hs[tim]) {
      ans++;
    } else if (hs[tim]) {
      break;
    }

    hs[tim] = true;
  }

  cout << ans << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}
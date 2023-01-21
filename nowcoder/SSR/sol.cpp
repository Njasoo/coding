#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int cnt_ssr = 0;
  string ssr = "SSR";
  for (int i = 0; i < 3; i++) {
    cnt_ssr += (int) ssr[i] * (int) pow(19, (2 - i));
  }
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
      cnt += (int) s[i] * (int) pow(19, (2 - i));
    }
    cout << cnt_ssr - cnt << '\n';
  }
  return 0;
}
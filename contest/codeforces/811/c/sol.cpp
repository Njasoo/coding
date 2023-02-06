#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int s;
    cin >> s;
    if (s < 10) {
      cout << s << '\n';
    } else {
      vector<int> vis(10);
      vector<int> ans;
      for (int i = 9; i >= 1; i--) {
        if (s >= i) {
          ans.push_back(i);
          s -= i;
        }
      }
      for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
      }
      cout << '\n';
    }
  }
  return 0;
}
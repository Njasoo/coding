#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    map<int, int> hs;
    for (int i = n - 1; i >= 0; i--) {
      if (++hs[a[i]] > 1) {
        break;
      }
      ans++;
    }
    cout << n - ans << '\n';
  }
  return 0;
}
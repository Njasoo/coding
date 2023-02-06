#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    const int inf = (int) 1e9;
    int l = -inf, r = inf;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      l = max(a[i] - x, l);
      r = min(a[i] + x, r);
      if (l > r) {
        ++ans;
        l = a[i] - x, r = a[i] + x;
      }
    }
    cout << ans << '\n';
    /*
    if (test == 1) {
      cerr << "test1" << endl;
      for (int i = 0; i < n; i++) {
        cerr << a[i] - x << " " << a[i] + x << endl;
      }
    }
    if (test == 2) {
      cerr << "test2" << endl;
      for (int i = 0; i < n; i++) {
        cerr << a[i] - x << " " << a[i] + x << endl;
      }
    }
    */
    /*
    if (test == 6) {
      cerr << "test6" << endl;
      for (int i = 0; i < n; i++) {
        cerr << a[i] - x << " " << a[i] + x << endl;
      }
    }
    if (test == 7) {
      cerr << "test7" << endl;
      for (int i = 0; i < n; i++) {
        cerr << a[i] - x << " " << a[i] + x << endl;
      }
    }
    */
  }
  return 0;
}
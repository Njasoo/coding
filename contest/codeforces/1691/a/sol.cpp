#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(2);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a % 2]++;
    }
    cout << min(c[0], c[1]) << '\n';
  }
  return 0;
}
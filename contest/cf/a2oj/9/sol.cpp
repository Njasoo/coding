#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  int now = 0;
  vector<int> a(12);
  for (int i = 0; i < 12; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  if (now >= k) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < 12; i++) {
    now += a[i];
    if (now >= k) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
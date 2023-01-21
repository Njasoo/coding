#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  sort(a.begin(), a.end(), [&](pair<int, int> i, pair<int, int> j) {
    return i.first < j.first;
  });
  if (a[0].first < a[1].first) {
    cout << a[0].second << '\n';
  } else {
    cout << "Still Rozdil" << '\n';
  }
  return 0;
}
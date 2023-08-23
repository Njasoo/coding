#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = accumulate(a.begin(), a.end(), 0LL);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) -> bool {
    return a[i] - b[i] > a[j] - b[j];
  });
//  for (int i = 0; i < n; i++) {
//    cerr << id[i] << " ";
//  }
//  cerr << endl;
  for (int i = 0; i < n - k; i++) {
    if (a[id[i]] - b[id[i]] <= 0) break;
    ans += b[id[i]] - a[id[i]];
  }
  cout << ans << '\n';
  return 0;
}
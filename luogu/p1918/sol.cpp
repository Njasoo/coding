#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> hash;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    hash[a[i]] = i + 1;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    auto it = hash.find(q);
    if (it == hash.end()) {
      cout << 0 << '\n';
    } else {
      cout << it->second << '\n';
    }
  }
  return 0;
}
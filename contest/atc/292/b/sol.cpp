#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> cnt(n);
  for (int i = 0; i < q; i++) {
    int op, x;
    cin >> op >> x;
    x--;
    if (op == 1) {
      cnt[x]++;
    } else if (op == 2) {
      cnt[x] += 2;
    } else if (op == 3) {
      cout << (cnt[x] >= 2 ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
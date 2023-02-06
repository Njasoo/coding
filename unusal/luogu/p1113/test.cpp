#include <bits/stdc++.h>

using namespace std;

int ans[10005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int maxans = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, len;
    cin >> x >> len;
    int tmp = 0;
    int y;
    while (cin >> y && y) {
      tmp = max(tmp, ans[y]);
    }
    ans[i] = tmp + len;
    maxans = max(maxans, ans[i]);
  }
  cout << maxans << '\n';
  return 0;
}
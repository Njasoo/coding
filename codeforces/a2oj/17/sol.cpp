#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int cnt = -1;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= 2 * n + 1; j++) {
      if (j >= n + 2 - i) {
        cout << ++cnt << " ";
      } else if (j <= n + 1 + i && j >= n + 2 - i) {
        cout << --cnt << " ";
      } else {
        cout << "  ";
      }
    }
    cout << '\n';
  }
  return 0;
}
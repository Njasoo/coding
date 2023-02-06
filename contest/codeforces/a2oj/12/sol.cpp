#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, a, b;
  cin >> r >> a >> b;
  int l = max(a + 1, r - b);
  cout << r - l + 1 << '\n';
  return 0;
}
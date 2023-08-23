#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  array<int, 3> a = {0, 0, 0};
  a[x] = 1;
  for (int i = n; i >= 1; i--) {
    if (i % 2) swap(a[0], a[1]);
    else swap(a[1], a[2]);
  }
  for (int i = 0; i < 3; i++) {
    if (a[i]) cout << i << '\n';
  }
  return 0;
}
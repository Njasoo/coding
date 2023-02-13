#include <bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << x << std::endl;
const int MN = 1e5;
int a[MN + 5], b[MN + 5];
long long suma[MN + 5], sumb[MN + 5];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    suma[i] = suma[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    sumb[i] = sumb[i - 1] + b[i];
  }
  int m;
  std::cin >> m;
  while (m--) {
    int op, l, r;
    std::cin >> op >> l >> r;
    if (op == 1) {
      std::cout << suma[r] - suma[l - 1] << '\n';
    } else {
      std::cout << sumb[r] - sumb[l - 1] << '\n';
    }
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr << #x << " = " << x << std::endl;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int ans = 1;
  std::vector<int> cnt(1440);
  for (int i = 0; i < n; i++) {
    int h, m;
    std::cin >> h >> m;
    int tot = h * 60 + m;
    ans = std::max(ans, ++cnt[tot]);
  }
  std::cout << ans << '\n';
  return 0;
}
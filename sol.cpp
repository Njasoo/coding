#include <bits/stdc++.h>
using namespace std;
#define db(x) std::cerr << #x << " = " << x << std::endl;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int ans = 1;
  std::map<std::pair<int, int>, int> cnt;
  for (int i = 1; i <= n; i++) {
    int h, m;
    std::cin >> h >> m;
    ans = std::max(ans, ++cnt[{h, m}]);
  }
  std::cout << ans << '\n';
  return 0;
}
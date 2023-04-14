#include <bits/stdc++.h>

#define db(x) std::cerr << #x << " = " << (x) << std::endl
#define dbp(x, y) std::cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << std::endl

void solve() {
    int a, b;
    std::cin >> a >> b;

    int ans = 1e9;

    for (int i = 1; i <= (int)1e5; i++) {
        ans = std::min(ans, i - 1 + (a + i - 1) / i + (b + i - 1) / i);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
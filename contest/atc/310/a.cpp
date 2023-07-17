#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p, q;
    std::cin >> n >> p >> q;

    int ans = p;
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        ans = std::min(ans, q + d);
    }

    std::cout << ans << '\n';
    
    return 0;
}
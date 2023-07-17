#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, t, m;
    std::cin >> n >> t >> m;

    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    std::vector<int> c(n);

    int ans = 0;

    auto dfs = [&](auto self, int x, int y) -> void {
        if (x == n) {
            if (y != t) return;
            bool ok = true;
            for (int i = 0; i < m; i++) {
                if (c[a[i]] == c[b[i]]) ok = false;
            }
            ans += ok;
            return;
        }
        for (int i = 0; i <= y; i++) {
            c[x] = i;
            self(self, x + 1, std::max(y, i + 1));
        }
    };
    dfs(dfs, 0, 0);
    std::cout << ans << '\n';
    
    return 0;
}
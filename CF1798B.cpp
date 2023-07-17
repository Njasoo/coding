#include <bits/stdc++.h>

void solve() {
    int m;
    std::cin >> m;

    std::vector<std::vector<int>> f(m);
    std::map<int, int> last;
    for (int i = 0; i < m; i++) {
        int n;
        std::cin >> n;
        f[i].resize(n);
        for (int j = 0; j < n; j++) {
            std::cin >> f[i][j];
            last[f[i][j]] = i + 1;
        }
    }
    std::vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (int) f[i].size(); j++) {
            if (last[f[i][j]] == i + 1) {
                ans[i] = f[i][j];
                break;
            }
        }
        if (ans[i] == -1) {
            std::cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cout << ans[i] << " \n"[i == m - 1];
    }
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
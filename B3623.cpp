#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> vis(n), temp(k);

    auto dfs = [&](auto self, int cnt) -> void {
        if (cnt == k) {
            for (int i = 0; i < k; i++) {
                std::cout << temp[i] << " \n"[i == k - 1];
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            temp[cnt] = i + 1;
            self(self, cnt + 1);
            vis[i] = 0;
        }
    };

    dfs(dfs, 0);
    
    return 0;
}
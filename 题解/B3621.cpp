#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> temp(n);

    auto dfs = [&](auto self, int cnt) -> void {
        if (cnt == n) {
            for (int i = 0; i < n; i++) {
                std::cout << temp[i] << " \n"[i == n - 1];
            }
            return;
        }
        for (int i = 1; i <= k; i++) {
            temp[cnt] = i;
            self(self, cnt + 1);
        }
    };

    dfs(dfs, 0);

    return 0;
}
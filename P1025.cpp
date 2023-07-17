#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1));

    std::function<int(int, int)> solve = [&](int u, int v) {
        if (v == 1) return 1;
        if (u < v) return 0;
        int res = solve(u - 1, v - 1);
        for (int i = 2; i <= v; i++) {
            res += solve(u - i, v - 1);
        }
    };
    
    return 0;
}
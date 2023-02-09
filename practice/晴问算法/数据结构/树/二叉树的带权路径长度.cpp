#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u != -1) p[i].push_back(u);
        if (v != -1) p[i].push_back(v);
    }
    std::vector<int> depth(n);
    int ans = 0;
    std::function<void(int u)> init = [&](int u) {
        for (int v : p[u]) {
            depth[v] = depth[u] + 1;
            init(v);
        }
    };
    std::function<void(int u)> solve = [&](int u) {
        if (p[u].empty()) ans += w[u] * depth[u];
        for (int v : p[u]) {
            solve(v);
        }
    };
    init(0);
    solve(0);
    std::cout << ans << '\n';
    return 0;
}
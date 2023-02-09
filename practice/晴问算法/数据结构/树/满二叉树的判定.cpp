#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u != -1) p[i].push_back(u);
        if (v != -1) p[i].push_back(v);
    }   
    int max_depth = 1, cnt = 1;
    std::function<void(int, int)> init = [&](int u, int depth) {
        for (auto v : p[u]) {
            cnt++;
            max_depth = depth + 1;
            init(v, depth + 1);
        }
    };
    init(0, 1);
    if (cnt == (1 << max_depth) - 1) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}
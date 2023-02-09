#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        p[i] = {u, v};
    }
    std::vector<int> id(n, -1);
    id[0] = 0;
    std::function<void(int u)> init = [&](int u) {
        if (p[u].first != -1) {
            id[p[u].first] = 2 * id[u] + 1;
            init(p[u].first);
        }
        if (p[u].second != -1) {
            id[p[u].second] = 2 * id[u] + 2;
            init(p[u].second);
        }
    };
    init(0);
    bool flag = true;
    std::set<int> set(id.begin(), id.end());
    for (auto x : set) {
        std::cerr << x << " ";
    }
    std::cerr << std::endl;
    for (std::set<int>::iterator it = set.begin(); it != set.end(); it++) {
        if (*it == -1 || *it == 0) continue;
        if (*it != *prev(it) + 1) {
            flag = false;
            break;
        }
    }
    std::cout << (flag ? "Yes" : "No") << '\n';
    return 0;
}
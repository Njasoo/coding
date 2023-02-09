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
    std::vector<int> depth(n), ans;
    std::vector<bool> vis(n);
    std::queue<int> que;
    que.push(0);
    ans.push_back(0);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : p[u]) {
            depth[v] = depth[u] + 1;
            que.push(v);
            if (vis[depth[v]]) continue;
            vis[depth[v]] = 1;
            ans.push_back(v);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
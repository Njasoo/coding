#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> ls(n, std::vector<int>(2, -1));
    // std::cerr << ls.size() << std::endl;
    // std::cerr << ls[0].size() << std::endl;
    for (int i = 1; i < n; i++) {
        int k, p;
        std::cin >> k >> p;
        k--;
        assert(k >= 0 && k < n);
        if (p) {
            int r = ls[k][1];
            // assert(r >= 0 && r < n);
            ls[k][1] = i;
            ls[i][0] = k;
            ls[i][1] = r;
            if (r != -1) ls[r][0] = i;
        } else {
            int l = ls[k][0];
            // std::cerr << "l = " << l << std::endl;
            // assert(l >= 0 && l < n);
            ls[k][0] = i;
            ls[i][1] = k;
            ls[i][0] = l;
            if (l != -1) ls[l][1] = i;
        }
    }

    int m;
    std::cin >> m;

    std::vector<bool> del(n);
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        x--;
        assert(x >= 0 && x < n);
        if (del[x]) continue;
        del[x] = true;
        int l = ls[x][0], r = ls[x][1];
        if (l != -1) ls[l][1] = r;
        if (r != -1) ls[r][0] = l;
    }

    int now;
    for (int i = 0; i < n; i++) {
        if (ls[i][0] == -1) {
            now = i;
            break;
        }
    }

    while (now != -1) {
        std::cout << now + 1 << " ";
        now = ls[now][1];
    }

    return 0;
}
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> f(n, std::vector<int>(m));
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> p[i] >> c;
        for (int j = 0; j < c; j++) {
            int x;
            std::cin >> x;
            x--;
            f[i][x] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (p[i] > p[j]) {
                bool flag = true;
                for (int k = 0; k < m; k++) {
                    if (f[i][k] && !f[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                // std::cerr << i << " " << j << std::endl;
                std::cout << "Yes\n";
                return 0;
            }
            if (p[i] >= p[j]) {
                bool flag = true;
                for (int k = 0; k < m; k++) {
                    if (f[i][k] && !f[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < m; k++) {
                    if (f[j][k] && !f[i][k]) {
                        // std::cerr << i << " " << j << std::endl;
                        std::cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "No\n";
    
    return 0;
}
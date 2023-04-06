#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                cnt += (s[i][k] == 'o' || s[j][k] == 'o');
            }
            if (cnt == m) ans++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
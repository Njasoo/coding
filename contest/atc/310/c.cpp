#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<std::string, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        std::string rs(s.rbegin(), s.rend());
        if (rs < s) s = rs;
        if (++cnt[s] == 1) ans++;
    }

    std::cout << ans << "\n";
    
    return 0;
}
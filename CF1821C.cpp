#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int ans = 1e9;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == ch) {
                flag = true;
                break;
            }
        }
        if (!flag) continue;
        int maxlen = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ch) {
                maxlen = std::max(maxlen, len);
                len = 0;
            } else {
                len++;
            }
        }
        maxlen = std::max(maxlen, len);
        int cnt = 0;
        while (maxlen) {
            maxlen /= 2;
            cnt++;
        }
        ans = std::min(ans, cnt);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
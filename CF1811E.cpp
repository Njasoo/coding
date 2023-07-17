#include <bits/stdc++.h>

void solve() {
    long long k;
    std::cin >> k;

    std::string ans;

    while (k) {
        int cnt = k % 9;
        if (cnt >= 4) cnt++;
        ans.push_back((char) cnt + '0');
        k /= 9;
    }

    std::reverse(ans.begin(), ans.end());

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}
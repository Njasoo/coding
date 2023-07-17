#include <bits/stdc++.h>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::sort(s.begin(), s.end());

    std::cout << s << '\n';
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, q;
    std::cin >> n >> a >> q;
    string s;
    std::cin >> s;
    int max_len = a, now_len = a;
    for (char c : s) {
        if (c == '+') {
            now_len++;
        } else {
            now_len--;
        }
        max_len = std::max(max_len, now_len);
    }
    if (max_len >= n) {
        std::cout << "YES\n";
    } else {
        int cnt = a + std::count(s.begin(), s.end(), '+');
        if (cnt >= n) std::cout << "MAYBE\n";
        else std::cout << "NO\n";
    }
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
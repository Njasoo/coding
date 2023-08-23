#include <bits/stdc++.h>

// 考虑加入一个负数会增加多少个总和为正数的子串, 得到有多少个正数后缀和就会增加多少答案

void solve() {
    int n, k;
    std::cin >> n >> k;

    int i = 0;
    while (i * (i + 1) < 2 * k) i++;

    if (i * (i + 1) == 2 * k) {
        for (int j = 0; j < i; j++) {
            std::cout << "1 ";
        }
        for (int j = i; j < n; j++) {
            std::cout << "-1000 ";
        }
        std::cout << "\n";
        return;
    }

    int d = k - i * (i - 1) / 2;

    for (int j = 0; j < i - 1; j++) {
        std::cout << "2 ";
    }
    std::cout << -2 * (i - 1 - d) - 1 << " ";
    for (int j = i; j < n; j++) {
        std::cout << "-1000 ";
    }
    std::cout << "\n";
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
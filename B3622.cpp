#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> (n - 1 - i) & 1) std::cout << "Y";
            else std::cout << "N";
        }
        std::cout << '\n';
    }

    return 0;
}
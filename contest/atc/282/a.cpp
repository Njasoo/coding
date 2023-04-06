#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cout << char('A' + i);
    }
    std::cout << '\n';
    return 0;
}
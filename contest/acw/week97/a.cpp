#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    std::cout << std::min(a, b) << " " << std::abs(a - b) / 2 << '\n';
    return 0;
}
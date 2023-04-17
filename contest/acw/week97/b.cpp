#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, bx;
    std::cin >> n >> bx;
    long long X = 0, Y = 0;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        X += num * (long long) std::pow(bx, n - 1 - i);
    }
    int m, by;
    std::cin >> m >> by;
    for (int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        Y += num * (long long) std::pow(by, m - 1 - i);
    }
    if (X == Y) std::cout << "=\n";
    else if (X > Y) std::cout << ">\n";
    else std::cout << "<\n";
    return 0;
}
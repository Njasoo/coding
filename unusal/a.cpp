#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    std::cout << (b / 2 == a ? "Yes" : "No") << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j > n) {
                std::cout << j - 1 << "\n";
                break;
            }
            if (s[j - 1] == s[j + i - 1]) {
                std::cout << j - 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
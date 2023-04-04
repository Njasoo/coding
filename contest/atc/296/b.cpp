#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> s(8);
    for (int i = 0; i < 8; i++) {
        std::cin >> s[i];
    }   

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '*') {
                std::cout << char('a' + j);
                std::cout << 8 - i << '\n';
            }
        }
    }

    return 0;
}
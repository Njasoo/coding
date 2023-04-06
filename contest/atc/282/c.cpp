#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::string s;
    std::cin >> n >> s;
    bool flag = 0; // 0->close, 1->open
    for (int i = 0; i < n; i++) {
        if (s[i] == '\"') {
            std::cout << s[i];
            flag ^= 1;
        } else if (s[i] == ',') {
            if (flag) std::cout << ",";
            else std::cout << ".";
        } else {
            std::cout << s[i];
        }
    }
    std::cout << "\n";
    return 0;
}
#include <bits/stdc++.h>
#define db(x) std::cerr << #x << " = " << (x) << std::endl
int main() {
    std::ios::sync_with_stdio(true);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            std::cout << i + 1 << '\n';
            return 0;
        }
    }   
    return 0;
}
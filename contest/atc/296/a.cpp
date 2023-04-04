#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";

    return 0;
}
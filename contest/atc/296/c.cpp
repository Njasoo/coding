#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    std::map<int, bool> hs;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        hs[a[i]] = true;
    }   

    for (int i = 0; i < n; i++) {
        if (hs[a[i] + x]) {
            std::cout << "Yes\n";
            return 0;
        }
    }

    std::cout << "No\n";

    return 0;
}
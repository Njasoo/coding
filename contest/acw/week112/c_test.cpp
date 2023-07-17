#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    while (std::next_permutation(a.begin(), a.end())) {
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}
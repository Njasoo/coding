#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n), sum(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i >= 2) {
            bool check = a[i - 2] >= a[i - 1] && a[i - 1] >= a[i];
            sum[i + 1] = sum[i] + check;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     std::cout << sum[i] << " \n"[i == n];
    // }

    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        int len = r - l + 1;
        if (len <= 2) {
            std::cout << len << "\n";
            continue;
        }
        std::cout << len - (sum[r] - sum[l + 1]) << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int reverse_number(const std::vector<int>& p) {
    int res = 0;
    int n = (int) p.size() - 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[j] < p[i]) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<long double>> f(n + 1, std::vector<long double>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> f[i][j];
        }
    }
    std::vector<int> order(n + 1);
    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        order[i] = i;
    }
    int k = fac(n);
    for (int i = 1; i <= k; i++) {
        std::next_permutation(order.begin() + 1, order.end());
        long double cnt = 1.0;
        for (int j = 1; j <= n; j++) {
            cnt *= f[j][order[j]];
        }
        if (reverse_number(order) % 2 == 1) {
            cnt *= -1;
        }
        ans += cnt;
    }
    std::cout << std::fixed << std::setprecision(3) << ans << '\n';
    return 0;
}
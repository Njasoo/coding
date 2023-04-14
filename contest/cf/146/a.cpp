#include <bits/stdc++.h>

#define db(x) std::cerr << #x << " = " << (x) << std::endl
#define dbp(x, y) std::cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << std::endl

void solve() {
    long long n, k;
    std::cin >> n >> k;

    if (n % std::gcd(2, k) == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
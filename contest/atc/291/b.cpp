#include <bits/stdc++.h>
#define db(x) std::cerr << #x << " = " << (x) << std::endl
int main() {
    std::ios::sync_with_stdio(true);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(5 * n);
    for (int i = 0; i < 5 * n; i++) {
        std::cin >> a[i];
    }   
    std::sort(a.begin(), a.end());
    long long sum = 0;
    for (int i = n; i < 4 * n; i++) {
        sum += a[i];
    }
    std::cout << std::fixed << std::setprecision(15) << 1.0 * sum / (3 * n) << '\n';
    return 0;
}
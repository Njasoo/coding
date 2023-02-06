#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
constexpr int MN = 100;
long long a[MN + 5], b[MN + 5], new_b[MN + 5];
bool special[MN + 5];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;   
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
        special[b[i]] = true;
    }
    long long ans = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (special[i]) {
            new_b[++idx] = a[i];
            continue;
        }
        ans += a[i];
    }
    std::sort(new_b + 1, new_b + 1 + m, [&](int i, int j) {
        return i > j;
    });
    for (int i = 1; i <= m; i++) {
        if (new_b[i] <= ans) {
            ans *= 2;
        } else {
            ans += new_b[i];
        }
    }
    std::cout << ans << '\n';
    return 0;
}
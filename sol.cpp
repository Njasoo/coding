#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << x << std::endl
constexpr int MN = 1E5;
std::map<std::string, int> id;
std::string s[MN + 5], t[MN + 5];
int f[MN + 5];
int leader(int x) {
    while (f[x] != x) x = f[x] = f[f[x]];
    return x;
}
bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    f[y] = x;
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::iota(f + 1, f + 1 + n, 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i] >> t[i];
        id[s[i]] = i;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!merge(id[s[i]], id[t[i]])) {
            flag = false;
            break;
        }
    }
    std::cout << (flag ? "Yes" : "No") << '\n';
    return 0;
}
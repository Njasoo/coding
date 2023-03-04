#include <bits/stdc++.h>
#define db(x) std::cerr << #x << " = " << (x) << std::endl
int up_div(int a, int b) {
    return a / b + (a % b != 0);
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a[0];
    int min = a[0];
    bool ok = true;
    for (int i = 1; i < n; i++) {
        std::cin >> a[i];
        ok &= a[i] == a[0];
    }
    if (ok) {
        std::cout << "0\n";
        return;
    }
    if (min == 1) {
        std::cout << "-1\n";
        return;
    }
    std::vector<std::pair<int, int>> ans;
    while (true) {
        bool check = false;
        int pos = std::min_element(a.begin(), a.end()) - a.begin();
        if (a[pos] == 1) {
            std::cout << "-1\n";
            return;
        }
        for (int i = 0; i < n; i++) {
            while (a[pos] < a[i]) {
                check = true;
                a[i] = up_div(a[i], a[pos]);
                ans.push_back({i, pos});
            }
        }
        if (!check) break;
    }
    ok = true;
    for (int i = 1; i < n; i++) {
        ok &= a[i] == a[0];
    }
    if (!ok) {
        std::cout << "-1\n";
    } else {
        std::cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            std::cout << x + 1 << " " << y + 1 << '\n';
        }
    }
}
int main() {
    std::ios::sync_with_stdio(true);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
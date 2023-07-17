#include <bits/stdc++.h>

// a[i]不改变, a[i - 1]--, a[i + 1]++ 或者 a[i - 1]++, a[i + 1]--
// a[1] == a[2] == a[3] = ... = a[n - 1] <= a[n]

void solve() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n % 2) {
        std::cout << "YES\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        long long cnt = a[i] - a[i - 1];
        a[i] -= cnt;
        a[i + 1] -= cnt;
    }

    // for (int i = 0; i < n; i++) {
    //     std::cout << a[i] << " \n"[i == n - 1];
    // }

    if (is_sorted(a.begin(), a.end())) {
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
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(a[i], g);
    }
    // cerr << "g: " << g << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (g != 1) {
        cout << "-1\n";
        return 0;
    }
    map<int, i64> dp;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [x, y] : dp) {
            int new_g = gcd(x, a[i]);
            if (dp.find(new_g) != dp.end()) {
                dp[new_g] = min(dp[new_g], y + b[i]);
            } else {
                dp[new_g] = y + b[i];
            }
        }
    }
    if (dp.find(1) != dp.end()) {
        cout << dp[1] << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}
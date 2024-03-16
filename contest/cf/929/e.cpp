#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    auto calc = [&](int u, int len) -> i64 {
        // return u + (u - 1) + (u - 2) + (u - len + 1)
        return 1LL * (u + u - len + 1) * len / 2;
    };
    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        l--;
        int r = lower_bound(s.begin() + l + 1, s.end(), s[l] + u) - s.begin(); // 找到能用完u的第一个位置，然后判断要不要往前挪
        i64 ans = -1e18;
        if (r <= n) {
            ans = calc(u, s[r] - s[l]);
        }
        if (r > l + 1) { // 还可以继续往前退
            if (calc(u, s[r - 1] - s[l]) >= ans) {
                ans = calc(u, s[r - 1] - s[l]);
                r--;
            }
        }
        cout << r << " \n"[q == 0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}
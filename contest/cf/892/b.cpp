#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int min_0 = (int) 1e9, min_1 = (int) 1e9;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        nth_element(a[i].begin(), a[i].begin() + 1, a[i].end());
        min_0 = min(min_0, a[i][0]);
        min_1 = min(min_1, a[i][1]);
        ans += a[i][1];
    }
    ans -= min_1;
    ans += min_0;
    cout << ans << '\n';
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
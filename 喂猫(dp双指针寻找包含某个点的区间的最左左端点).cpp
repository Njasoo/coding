#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> t(m);
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        cin >> t[i].first >> t[i].second;
        t[i].first--, t[i].second--;
        cnt[t[i].first]++;
        if (t[i].second + 1 < n) {
            cnt[t[i].second + 1]--;
        }
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<int> mnl(n);
    iota(mnl.begin(), mnl.end(), 0);
    sort(t.begin(), t.end());
    int j = 0;
    for (auto [x, y] : t) {
        while (j < n && y >= j) {
            mnl[j] = min(mnl[j], x);
            j++;
        }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] += cnt[i];
        if (mnl[i] - 1 >= 0) {
            dp[i] += dp[mnl[i] - 1];
        }
        if (i > 0) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }
    cout << dp[n - 1] << '\n';
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
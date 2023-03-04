#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26 + 32);
    for (int i = 0; i < n; i++) {
        int ch = s[i] - 'A';
        cnt[ch]++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += min(cnt[i], cnt[i + 32]);
    }
    for (int i = 0; i < 26 && k > 0; i++) {
        int temp1 = cnt[i] + cnt[i + 32];
        int temp2 = min(cnt[i], cnt[i + 32]);
        ans += min(temp1 / 2 - temp2, k);
        k -= min(temp1 / 2 - temp2, k);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
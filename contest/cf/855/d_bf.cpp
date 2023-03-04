#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, bool> vis;
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        string temp = s;
        temp.replace(i, 2, "");
        if (vis[temp]) continue;
        if (!vis[temp]) {
            vis[temp] = true;
            ans++;
        }
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
#include <bits/stdc++.h>
using namespace std;
bool vis[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        s = ' ' + s;
        memset(vis, 0, sizeof(vis));
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[s[i] - 'a']) {
                vis[s[i] - 'a'] = 1;
            } else {
                m += 2;
                memset(vis, 0, sizeof(vis));
            }
        }
        cout << n - m << '\n';
    }       
    return 0;
}
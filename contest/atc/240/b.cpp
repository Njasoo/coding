#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, bool> vis;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (!vis[a]) {
            vis[a] = 1;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
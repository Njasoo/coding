#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL x;
    cin >> x;
    map<LL, bool> vis;
    int ans = 0;
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
            if (!vis[x]) ans++;
            vis[x] = true;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ans++;
    cout << ans << '\n';
    return 0;
}
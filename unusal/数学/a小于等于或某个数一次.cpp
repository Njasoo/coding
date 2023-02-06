#include <bits/stdc++.h>

using namespace std;

/*
a <= (a | z)
*/

void solve() {
    int n, z;
    cin >> n >> z;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        a |= z;
        ans = max(ans, a);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }      
    return 0;
}
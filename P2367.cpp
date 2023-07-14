#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 6;
int d[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int pre, a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        d[i] = a - pre;
        pre = a;
    }      
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        ans = min(ans, d[i]);
    }
    cout << ans << '\n';
    return 0;
}
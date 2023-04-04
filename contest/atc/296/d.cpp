#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    long long ans = 1e18;
    for (long long i = 1; i <= min(n, 1000000LL); i++) {
        long long j = m / i;
        if (i * j < m) j++;
        if (j <= n) ans = min(ans, i * j);
    }
    if (ans == 1e18) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}
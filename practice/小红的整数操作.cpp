#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    int g = gcd(x, y);
    x /= g;
    y /= g;
    int ans = 0;
    for (int i = 1; 1LL * x * i <= r && 1LL * y * i <= r; i++) {
        if (1LL * x * i >= l && 1LL * y * i >= l) ans++;
    }
    cout << ans << '\n';
    return 0;
}
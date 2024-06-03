#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = a + b / 3;
    b %= 3;
    if (b == 0) {
        ans += (c + 2) / 3;
    } else if (b == 1) {
        if (c < 2) {
            cout << "-1\n";
            return;
        } else {
            c -= 2;
            ans++;
            ans += (c + 2) / 3;
        }
    } else if (b == 2) {
        if (c < 1) {
            cout << "-1\n";
            return;
        }
        c--;
        ans++;
        ans += (c + 2) / 3;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
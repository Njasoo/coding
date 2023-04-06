#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x1, y1, x2, y2, n;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int cnt1 = min({x1, n + 1 - x1, y1, n + 1 - y1});
    int cnt2 = min({x2, n + 1 - x2, y2, n + 1 - y2});
    cout << abs(cnt1 - cnt2) << '\n';
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
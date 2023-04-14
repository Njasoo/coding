#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cnt1 = 0;
    if (x1 + 1 <= n) cnt1++;
    if (x1 - 1 > 0) cnt1++;
    if (y1 + 1 <= m) cnt1++;
    if (y1 - 1 > 0) cnt1++;
    int cnt2 = 0;
    if (x2 + 1 <= n) cnt2++;
    if (x2 - 1 > 0) cnt2++;
    if (y2 + 1 <= m) cnt2++;
    if (y2 - 1 > 0) cnt2++;
    cout << min(cnt1, cnt2) << '\n';
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
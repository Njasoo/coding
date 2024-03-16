#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N1 = 2e3 + 5, N2 = 1e5 + 5;
int a[N1], v[N2], b[N1];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
    }
    ll ans = 0;
    for (int i = 1; i <= d; i++) {
        if (n + (d - i) / 2 <= ans) { // 单次最大贡献为n
            break;
        }
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += (a[j] == j);
        }
        ans = max(ans, 1LL * cnt + (d - i) / 2);
        for (int j = 1; j <= v[(i - 1) % k + 1]; j++) {
            a[j]++;
        }
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
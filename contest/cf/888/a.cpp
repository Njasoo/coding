#include <bits/stdc++.h>
using namespace std;
const int N = 55;
long long h[N];
void solve() {
    long long n, m, k, H;
    cin >> n >> m >> k >> H;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        bool flag = 0;
        for (long long j = 1; j <= m; j++) {
            for (long long o = 1; o <= m; o++) {
                if (j == o) continue;
                if (llabs(H - h[i]) == llabs(j * k - o * k)) {
                    ans++;
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
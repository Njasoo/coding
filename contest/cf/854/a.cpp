#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) <<endl
const int N = 1e5 + 5;
int p[N], cnt[N], ans[N];
void solve() {
    int n, m;
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    memset(ans, -1, sizeof(ans));
    int last = n;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        cnt[p[i]]++;
        if (cnt[p[i]] == 1 && last >= 1) {
            ans[last] = i;
            last--;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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
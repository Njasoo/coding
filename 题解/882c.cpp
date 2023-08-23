#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 2e5 + 5;
int a[N], pre[300];

void solve() {
    int n;
    cin >> n;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = 0, ans = 0;
    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        cur ^= a[i];
        for (int j = 0; j < (1 << 8); j++) {
            if (pre[j]) ans = max(ans, cur ^ j);
        }
        pre[cur] = 1;
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
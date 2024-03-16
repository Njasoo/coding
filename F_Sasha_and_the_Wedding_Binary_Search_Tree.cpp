#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

/**
 * 性质：二叉搜索树的中序遍历是递增序列
 * -1的个数是球，-1两边的非-1元素之差+1为盒子个数，球同盒不同的组合问题
*/

const int N = 5e5 + 5, MOD = 998244353, MN = 5e5;
int l[N], r[N], val[N], temp[N];
ll fac[N], inv_fac[N];
int cur;

void dfs(int u) {
    if (l[u] != -1) dfs(l[u]);
    temp[++cur] = val[u];
    if (r[u] != -1) dfs(r[u]);
}

ll power(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v % 2) res = res * u % MOD;
        u = u * u % MOD;
        v /= 2;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= MN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MN] = power(fac[MN], MOD - 2);
    for (int i = MN - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

void solve() {
    int n, C;
    cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> val[i];
    }
    cur = 0;
    dfs(1);
    temp[++cur] = C;
    // for (int i = 0; i <= cur; i++) {
    //     cerr << temp[i] << " ";
    // }
    // cerr << endl;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (temp[i] == -1) {
            for (int j = i + 1; j <= n + 1; j++) {
                if (temp[j] != -1) {
                    // cerr << i - 1 << " " << j << endl;
                    int ball = j - i;
                    int box = temp[j] - temp[i - 1] + 1;
                    // db(ball), db(box), el;
                    ll cnt = 1;
                    for (int k = box; k <= ball + box - 1; k++) {
                        cnt = cnt * k % MOD;
                    }
                    // db(inv_fac[ball]), el;
                    cnt = cnt * inv_fac[ball] % MOD;
                    ans = ans * cnt % MOD;
                    i = j;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    temp[0] = 1;
    init();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
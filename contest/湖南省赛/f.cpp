#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vt vector
#define pb push_back
#define sz(x) (int) x.size()
#define p_queue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 10000;
int s[N + 5], t[N + 5];
ll dp[405][405], best[405][405];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }   
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e12;
        }
    }
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], w);
    }
    for (int k = 1; k <= 400; k++) {
        for (int i = 1; i <= 400; i++) {
            for (int j = 1; j <= 400; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            best[i][j] = 1e12;
        }
    }
    for (int i = 1; i <= 400; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 1; k <= 400; k++) {
                best[i][j] = min(best[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = 1e12;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        debug(i);
        for (int j = 1 + i; j <= n + i; j++) {
            debug(best[s[(j - 1) % n + 1]][t[j - i]]);
            cnt += best[s[(j - 1) % n + 1]][t[j - i]];
        }
        ans = min(ans, cnt);
    }
    cout << (ans == (ll) 1e12 ? -1 : ans) << '\n';
    return 0;
}
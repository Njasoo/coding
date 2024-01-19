#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
int m, n;
long long w[N][N], p[N], lev[N], dis[N];
bool tag[N], vis[N];

long long dijkstra(int l, int r) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e18;
        vis[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (lev[i] >= l && lev[i] <= r) tag[i] = 1;
        else tag[i] = 0;
    }

    debug(l, r);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (tag[i]) {
            debug(i, lev[i]);
            cnt++;
        }
    }

    dis[1] = 0;
    long long mn_dis = 1e18;
    int t = cnt;
    while (t--) {
        int u = -1;
        long long mn = 1e18;
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] <= mn && tag[i]) {
                mn = dis[i];
                u = i;
                ok = 1;
            }
        }
        assert(ok);
        // if (!ok) break;
        vis[u] = 1;
        for (int v = 1; v <= n; v++) {
            if (tag[v]) {
                dis[v] = min(dis[v], dis[u] + w[u][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        debug(i, dis[i]);
        dis[i] += p[i]; // 假设第i个点为最后一个点，则这个点没有用替代品换取优惠，则加上这个物品的价格
        debug("after", i, dis[i]);
        mn_dis = min(mn_dis, dis[i]);
    }
    debug(mn_dis);
    return mn_dis;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                w[i][j] = 0;
            } else {
                w[i][j] = 1e18;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> p[i] >> lev[i] >> x;
        for (int j = 1; j <= x; j++) {
            int v;
            long long ww;
            cin >> v >> ww;
            w[i][v] = ww;
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         debug(w[i][j]);
    //     }
    // }

    long long ans = 1e18;
    for (int i = 0; i <= m; i++) {
        int l = lev[1] - i;
        int r = lev[1] + (m - i);
        ans = min(ans, dijkstra(l, r));
    }
    cout << ans << '\n';

    return 0;
}
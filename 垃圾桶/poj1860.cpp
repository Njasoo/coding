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

#define ll long long
#ifndef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

// 反过来找正环

const int N = 205;
int u[N], v[N];
double r[N], c[N], dis[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s;
    double V;
    cin >> n >> m >> s >> V;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cnt++;
        cin >> u[cnt] >> v[cnt] >> r[cnt] >> c[cnt];
        cnt++;
        u[cnt] = v[cnt - 1];
        v[cnt] = u[cnt - 1];
        cin >> r[cnt] >> c[cnt];
    }
    for (int i = 1; i <= cnt; i++) {
        debug(u[i], v[i], r[i], c[i]);
    }
    memset(dis, 0, sizeof dis);
    debug(dis[0]);
    dis[s] = V;
    int t = n - 1;
    while (t--) {
        for (int i = 1; i <= cnt; i++) {
            if (dis[v[i]] < (dis[u[i]] - c[i]) * r[i]) {
                dis[v[i]] = (dis[u[i]] - c[i]) * r[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        debug(i, dis[i]);
    }
    for (int i = 1; i <= cnt; i++) {
        debug(u[i], v[i], dis[v[i]], (dis[u[i]] - c[i]) * r[i]);
        if (dis[v[i]] < (dis[u[i]] - c[i]) * r[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
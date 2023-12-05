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
#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
bool win[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        win[u][v] = 1;
    }   
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                win[i][j] = win[i][j] || (win[i][k] && win[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (win[i][j] || win[j][i]) {
                cnt++;
            }
        }
        if (cnt == n - 1) ans++;
    }
    cout << ans << '\n';
    return 0;
}
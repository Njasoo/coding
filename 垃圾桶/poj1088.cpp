#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
long long f[N][N], dp[N][N];
int n, m;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

long long solve(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    long long res = 0;
    for (int k = 0; k < 4; k++) {
        int dx = dir[k][0];
        int dy = dir[k][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (f[nx][ny] >= f[x][y]) continue;
        res = max(res, solve(nx, ny));
    }
    return dp[x][y] = res + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << '\n';
    return 0;
}
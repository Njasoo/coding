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

//如果是四维dp,dp[mask_2][mask_1][mask][i]

int state[101];//每一行的地形状况
int cnt1[1024];//计算每种炮兵摆放状态的炮兵数量
int dp[1024][1024][11];//dp[i][j][k]:表示第k行，该行摆放状态为j，上一行的摆放状态为i时的最大炮兵摆放数量（前k行总量）

int count_1(int mask) {
    int res = 0;
    while (mask) {
        if (mask & 1)res++;
        mask >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            state[i] <<= 1;
            if (ch == 'H')state[i]++; //山地设置为1，这样炮兵放置在山地上的时候，&的结果为1，可由此判断非法情况
        }
    }
    for (int mask = 0; mask < (1 << m); mask++) {
        cnt1[mask] = count_1(mask); //提前计算每种炮兵摆放的方案
    }
    //处理一下第一行的情况，第一行没有上一行的状态
    for (int mask = 0; mask < (1 << m); mask++) {
        if (mask & state[1] || (mask & (mask << 1)) || (mask & (mask << 2)))continue;
        dp[0][mask][1] = cnt1[mask];
    }
    //第二行的情况，第二行，没有前前行的状态
    for (int mask1 = 0; mask1 < (1 << m); mask1++) {
        for (int mask2 = 0; mask2 < (1 << m); mask2++) {
            if ((mask1 & mask2) || (mask1 & state[1]) || (mask2 & state[2]) || (mask1 & (mask1 << 1)) || (mask1 & (mask1 << 2)) || (mask2 & (mask2 << 1)) || (mask2 & (mask2 << 2)))continue;
            dp[mask1][mask2][2] = cnt1[mask1] + cnt1[mask2];
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int mask_2 = 0; mask_2 < (1 << m); mask_2++) {
            if ((mask_2 & state[i - 2]) || (mask_2 & (mask_2 << 1)) || (mask_2 & (mask_2 << 2)))continue;
            for (int mask_1 = 0; mask_1 < (1 << m); mask_1++) {
                if (mask_1 & mask_2)continue;
                if ((mask_1 & state[i - 1]) || (mask_1 & (mask_1 << 1)) || (mask_1 & (mask_1 << 2)))continue;
                for (int mask = 0; mask < (1 << m); mask++) {
                    if ((mask & mask_1) || (mask & mask_2))continue;
                    if ((mask & state[i]) || (mask & (mask << 1)) || (mask & (mask << 2)))continue;
                    dp[mask_1][mask][i] = max(dp[mask_1][mask][i], dp[mask_2][mask_1][i - 1] + cnt1[mask]);
                }
            }
        }
    }
    int ans = 0;
    for (int mask_1 = 0; mask_1 < (1 << m); mask_1++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            ans = max(ans, dp[mask_1][mask][n]);
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 25;
double x[N], y[N];
double dis[N][N];
double dp[N][1 << 15]; // dp[i][j]：终点为i，经过的点的二进制表示为j的最短路径和
// 状态转移，枚举到达终点的前一个点,加上到新的终点的路径

double calc(int i, int j)
{
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(dp, 127, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    x[0] = y[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dis[i][j] = dis[j][i] = calc(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][(1 << (i - 1))] = dis[i][0];
    }
    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (k & (1 << (i - 1)) == 0)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (k & (1 << (j - 1)) == 0)
                    continue;
                dp[i][k] = min(dp[i][k], dp[j][k ^ (1 << (i - 1))] + dis[i][j]);
                // cout << "dp[i][k]=" << dp[i][k] << endl;
            }
        }
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}
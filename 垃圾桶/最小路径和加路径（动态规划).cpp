#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << (#x) << "=" << x << " "
#define el cerr << endl

const int N = 1005;
long long coin[N][N], dp[N][N], mv[N][N]; // 1: up, 2: down, 3: left, 4: right

void print_ans(int i, int j) {
    if (i == 1 && j == 1) {
        cout << "(" << i << ", " << j << ") ";
        return;
    }
    if (i == 1) {
        print_ans(i, j - 1);
    } else if (j == 1) {
        print_ans(i - 1, j);
    } else if (dp[i - 1][j] < dp[i][j - 1]) {
        print_ans(i - 1, j);
    } else {
        print_ans(i, j - 1);
    }
    cout << "-> ";
    cout << "(" << i << ", " << j << ") ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> coin[i][j];
        }
    }
    dp[1][1] = coin[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] += dp[i - 1][1] + coin[i][1];
        mv[i][1] = 2;
    }
    for (int j = 2; j <= m; j++) {
        dp[1][j] = dp[1][j - 1] + coin[1][j];
        mv[1][j] = 4;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + coin[i][j];
                mv[i][j] = 2;
            } else {
                dp[i][j] = dp[i][j - 1] + coin[i][j];
                mv[i][j] = 4;
            }
        }
    }
    cout << "maximum coin: " << dp[n][m] << '\n';
    print_ans(n, m);
    return 0;
}
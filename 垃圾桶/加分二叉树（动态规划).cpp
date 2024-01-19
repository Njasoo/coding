#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << (#x) << "=" << x << " "
#define el cerr << endl

const int N = 35;
long long dp[N][N], a[N];
int root[N][N];

void print_ans(int l, int r) {
    if (l > r) return;
    cout << root[l][r] << " ";
    if (l == r) return;
    print_ans(l, root[l][r] - 1);
    print_ans(root[l][r] + 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        dp[i][i - 1] = dp[i + 1][i] = 1;
        root[i][i] = i;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                if (dp[i][j] < dp[i][k - 1] * dp[k + 1][j] + dp[k][k]) {
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + dp[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    print_ans(1, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// dp[i]: 1到i最小危险度总和

const int N = 1005;
int a[N], dp[N], cnt[25], sum[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int j = i;
        int dist = 0;
        while (j <= n && dist <= k) {
            if (++cnt[a[j]] == 1) dist++;
            j++;
        }
        ans1++;
        if (dist == k + 1) {
            // cerr << i << " " << j - 2 << endl;
            i = j - 2;
        } else {
            // cerr << i << " " << j - 1 << endl;
            i = j - 1;
        }
        memset(cnt, 0, sizeof(cnt));
    }
    cout << ans1 << '\n';
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        int dist = 0;
        for (int j = i; j <= n; j++) {
            if (++cnt[a[j]] == 1) dist++;
            sum[i][j] = dist;
        }
    }
    // db(sum[1][3]);
    // db(sum[2][8]);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (sum[j][i] <= k) {
                dp[i] = min(dp[i], dp[j - 1] + sum[j][i]);
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
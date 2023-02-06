#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int f[N][N], sum[N][N];
bool check(int mid) {
    for (int i = mid; i <= n; i++) {
        for (int j = mid; j <= m; j++) {
            int cnt = sum[i][j] - sum[i][j - mid] - sum[i - mid][j] + sum[i - mid][j - mid];
            if (cnt == mid * mid) return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;       
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }
    int l = 0, r = min(n, m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + f[i][j];
        }
    }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
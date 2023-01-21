#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                cin >> ch;
                a[i][j] = ch - '0';
            }
        }
        int ans = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt = a[i][j] + a[j][n - 1 - i] + a[n - 1 - i][n - 1 - j] + a[n - 1 - j][i];
                ans += min(cnt, 4 - cnt);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int MOD = 1e9 + 7;
int dp[5005][1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    while (cin >> a >> b) {
        int la = a.size(), lb = b.size();
        a = ' ' + a, b = ' ' + b;
        for (int i = 0; i <= la; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD; // 可以发现只和[i - 1]有关，可以删掉一维
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[la][lb] << '\n';
    }
    return 0;
}
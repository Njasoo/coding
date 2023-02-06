#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int N = 2005;
int dp[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    a = ' ' + a, b = ' ' + b;
    // 要求最小值，所以把全部dp值设为无限大
    memset(dp, 0x3f, sizeof(dp));
    // 递归终结返回值
    dp[0][0] = 0;
    for (int j = 1; j <= lb; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= la; i++) {
        dp[i][0] = i;
    }
    // 两个回圈代表遍历所有状态，初始状态就不用遍历了
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            int cnt;
            if (a[i] == b[j]) {
                cnt = dp[i - 1][j - 1];
            } else {
                cnt = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = min({dp[i][j], cnt, dp[i - 1][j] + 1, dp[i][j - 1] + 1}); // min的参数可以是一个数组
        }
    }
    cout << dp[la][lb] << '\n';
    return 0;
}
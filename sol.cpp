#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// 定义dp[i][j]：b的前j个字符以子序列的形式出现在a的前i个字符里多少次
// 子序列的定义可以看做是删掉几个字符得到的序列
// 所以我们的决策应该是决定要不要删掉第i个字符
const int MOD = 1e9 + 7;
string a, b;
long long dp[5005][1005];
long long solve(int lena, int lenb) {
    if (dp[lena][lenb] != -1) return dp[lena][lenb];
    if (lenb == 0) return dp[lena][lenb] = 1; // 啥也没有是不是也算是一种方案？是的，全部删掉
    if (lena == 0) return dp[lena][lenb] = 0;
    if (a[lena] == b[lenb]) {
        // b[lenb]可以拼接在前面的情况？
        return dp[lena][lenb] = (solve(lena - 1, lenb - 1) + solve(lena - 1, lenb)) % MOD; // 后面这个是b[lenb]替代b[lenb - 1], 前面是拼接上去的情况
    } else {
        return dp[lena][lenb] = solve(lena - 1, lenb); // 跟前一个情况一样，没有什么可以改变
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> a >> b) {
        memset(dp, -1, sizeof(dp));
        int la = a.size(), lb = b.size();
        a = ' ' + a;
        b = ' ' + b;
        cout << solve(la, lb) << '\n';   
    }
    return 0;
}
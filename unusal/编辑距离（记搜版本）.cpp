#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// dp[i][j]: a的前i个字符变成b的前j个字符所需的最小步数
// 先考虑搜索吧，毕竟我的dp永远只会模板，正推应该是不可能退出来了，记搜写出来，dp应该就不难了，前提我这次要完全理解它
// 状态难想，不过越少越好，尽量往简单的去想，虽然想出来了也不会推
const int N = 2005;
int dp[N][N];
string A, B;
int solve(int lena, int lenb) {
    if (dp[lena][lenb] != -1) return dp[lena][lenb];
    // 假设长度是不断减少的，那最后什么是可以确定的
    if (lena == 0) return dp[lena][lenb] = lenb; // 添加lenb个，只有这种方法了
    if (lenb == 0) return dp[lena][lenb] = lena; // 删除lena个，也是只有这种方法
    // 如果A[lena] ！= B[lenb]，可以先试一下更改A[lena]等于B[lenb]，然后比较一下哪种方法更好
    int res;
    if (A[lena] == B[lenb]) {
        res = solve(lena - 1, lenb - 1);
    } else {
        res = solve(lena - 1, lenb - 1) + 1;
    }
    // 最难的一步，想想还有什么操作可以比较，添加和删除
    // 下面是经典的(i - 1, j - 1), (i, j - 1), (i - 1, j)环节，虽然想不出来，但是可以尝试理解
    // A的前i - 1个字符变成B的前j个，需要多少步，如果前i - 1已经可以变成B，那么最后一个就是多余的，需要删掉，所以加1
    // A的前i个字符变成B的前j-1个，那么现在B多了一个，所以需要再添加一项，这是添加的部分
    // 这样的话，更改，删除和添加的操作都有了，那么就来贪心地比较他们的步数取最小值
    return dp[lena][lenb] = min(min(solve(lena, lenb - 1) + 1, solve(lena - 1, lenb) + 1), res);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    int lena = A.size();
    int lenb = B.size();
    A = ' ' + A;
    B = ' ' + B;
    cout << solve(lena, lenb) << '\n';
    return 0;
}
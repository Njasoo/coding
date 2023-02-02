#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// a中最多10个不同的字母，假设a中不同字母的数量是m
// 从中选k个应该被替换的字母总数为mCk，最多的情况就是10C5 = 252（草，这个条件被忽略了一晚上）
// 252 * O(n) -> 爆搜哪几个字母应该被加入集合q
// 学那么多算法有啥用，最基础的都不会用(-_-)，贪心做多了，久久碰到搜索都看不出来了
// 怎么超时了？
// 好像是我把组合搞成排列了，有很多情况重复计算了（是的，然后时间复杂度就变成O(n * m!)...理所当然地炸了）
// 连组合递归都忘记怎么写了，重新回想怎么写组合递归，坐标递增？
int n, k, dis, last;
long long ans;
string a, b;
char canuse[15];
bool vis[26];
void dfs(int now) {
    if (now == k + 1 || now == dis + 1) {
        long long cnt = 0;
        string tempa = a;
        for (int i = 1; i <= n; i++) {
            if (vis[tempa[i] - 'a']) {
                tempa[i] = b[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (tempa[j] == b[j] && j <= n) {
                j++;
            }
            long long len = j - i;
            i = j;
            cnt += len * (len + 1) / 2; // 爆了，还是long long安全
        }
        ans = max(ans, cnt);
        return;
    }
    for (int i = last + 1; i <= dis; i++) {
        if (!vis[canuse[i] - 'a']) {
            vis[canuse[i] - 'a'] = 1;
            int temp_last = last;
            last = i;
            dfs(now + 1);
            last = temp_last;
            vis[canuse[i] - 'a'] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        last = 0;
        ans = 0;
        dis = 0;
        cin >> n >> k >> a >> b;
        a = ' ' + a, b = ' ' + b;
        for (int i = 1; i <= n; i++) {
            if (!vis[a[i] - 'a']) {
                vis[a[i] - 'a'] = 1;
                canuse[++dis] = a[i];
            }
        }
        memset(vis, 0, sizeof(vis)); // 重复利用
        dfs(1);
        cout << ans << '\n';
    }   
    return 0;
}
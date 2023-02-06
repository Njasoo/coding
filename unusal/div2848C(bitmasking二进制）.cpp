#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
bool vis[26];
char canuse[15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        a = ' ' + a, b = ' ' + b;
        memset(vis, 0, sizeof(vis));
        int dis = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[a[i] - 'a']) {
                vis[a[i] - 'a'] = 1;
                canuse[++dis] = a[i];
            }
        }
        // 0000 1 ~ 1111 1
        long long ans = 0;
        for (int mask = 1; mask <= (1 << (dis + 1)) - 1; mask += 2) { // 这个1是加在第二位的，这个方法从1开始是有点麻烦
            // db(__builtin_popcount(mask));
            if (__builtin_popcount(mask) != min(dis, k) + 1) continue; // 这个函数的时间复杂度是O(log(N))吗，如果是的话这个程序应该比dfs慢一点
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i <= dis; i++) {
                if ((mask >> i) & 1) {
                    vis[canuse[i] - 'a'] = 1;
                }
            }
            string tempa = a;
            for (int i = 1; i <= n; i++) {
                if (vis[tempa[i] - 'a']) {
                    tempa[i] = b[i];
                }
            }
            long long cnt = 0;
            for (int i = 1; i <= n; i++) {
                int j = i;
                while (tempa[j] == b[j] && j <= n) {
                    j++;
                }
                // cerr << "i: " << i << " " << "j: " << j << endl;
                long long len = j - i;
                i = j;
                cnt += len * (len + 1) / 2;
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }   
    return 0;
}
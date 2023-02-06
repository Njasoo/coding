#include <bits/stdc++.h>

using namespace std;

/*
知识点: 
(1) 对于一个无向图, 删去一个点, 减少的边数等于删去点的度数
(2) 只有相邻的点才有公共边

有n个人, 然后m对朋友, 尽量要邀请足够多的人
有一对朋友出现在派对, 他们就会吃一个蛋糕, 吃的蛋糕总数一定要是偶数
第i个人缺席, 就会产生对应a[i]的不高兴值
求最小的不高兴值

显然m是偶数时, 我们可以邀请所有人, 所以答案为零

数学模型: 朋友和朋友相连, 组成一个无向图, 总共边数为n, 假设删除点v, deg(v) = m
那么边数等于n - m
目标: 删去若干个点, 使得总边数为偶数

所以先考虑度数为奇数的点

另外一种就是考虑度数为偶数的点
考虑两个相邻的点, 它们的度数都是偶数, 记为u和v
删去u, 边数仍是奇数, 这时, 再删去相邻的v, 总边数减去奇数, 因为无法重复删去u, v的公共边
或者换个说法, 删去u时, v的度数也对应地减少1, 所以这时候v的度数就是奇数
*/

void solve() {
    int n, m;
    cin >> n >> m;
    int a[100001], deg[100001], x[100001], y[100001];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[i] = 0; // 记得预设为零
    }    
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        deg[x[i]]++;
        deg[y[i]]++;
    }
    int ans = 100001;
    if (m % 2 == 0) {
        ans = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 == 1) {
            ans = min(ans, a[i]);
        } 
    }
    for (int i = 1; i <= m; i++) {
        if (deg[x[i]] % 2 == 0 && deg[y[i]] % 2 == 0) {
            ans = min(ans, a[x[i]] + a[y[i]]);  
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
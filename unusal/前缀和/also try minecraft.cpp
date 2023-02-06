#include <bits/stdc++.h>

using namespace std;

/*
翻译:
你是游戏新版本的测试员, 这个版本会在游戏里面加入任务
这个游戏时间的地图是一个数组a, 长度为n, ith位置高度为a[i]
有m个任务要你去测试, 第j个任务会用sj和tj来表示, 你需要从第sj列到tj列, 任务一开始, 你在sj列出现
每次移动, 你可以往左右移动一个单位
你有幽灵靴, 可以让你飞, 但是因为有bug, 所以只能在你往上移动并且拥有无限飞行时间时才能用
从高度p移动到低处q, 会有落地伤害p-q(p>q)

目标: 完成所有m个任务, 并且使得落地伤害最小

一个一个任务的完成, 这个应该是用前缀和

*/

long long h[100005], tor[100005], tol[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (i > 1) {
            tor[i] = tor[i - 1] + max(0LL, h[i - 1] - h[i]);
            tol[i] = tol[i - 1] + max(0LL, h[i] - h[i - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << tor[t] - tor[s] << "\n";
        } else {
            cout << tol[s] - tol[t] << "\n";
        }
    }
    return 0;
}
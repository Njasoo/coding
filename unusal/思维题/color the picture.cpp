#include <bits/stdc++.h>

using namespace std;

/*
方法: 纯模拟和思维, 结论主要靠猜

一张图片表示一个n*m的网格, 你有k种不同颜色的染料(pigment), 每种染料i最多可以染a[i]个格子
漂亮的图片定义为每个格子至少有三个颜色相同的相邻格子

单看横坐标, 1的左边是n
纵坐标以此类推

解决方法, 两行两行或两列两列地涂满, 看行或列是否能涂满
如果n或m其中一个为奇数

那么至少有一种颜色要涂三行
*/

long long a[100005];

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    long long rows_painted = 0;
    bool rows_all2 = 1;
    long long cols_painted = 0;
    bool cols_all2 = 1;
    for (int i = 1; i <= k; i++) {
        if (a[i] / n >= 2) {
            cols_painted += a[i] / n;
            if (a[i] / n >= 3) {
                cols_all2 = 0;
            }
        }
        if (a[i] / m >= 2) {
            rows_painted += a[i] / m;
            if (a[i] / m >= 3) {
                rows_all2 = 0;
            }
        }
    }
    if (rows_painted >= n && (rows_all2 == 0 || n % 2 == 0)) {
        cout << "Yes" << '\n';
    } else if (cols_painted >= m && (cols_all2 == 0 || m % 2 == 0)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
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
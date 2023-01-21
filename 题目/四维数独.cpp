#include <bits/stdc++.h>

using namespace std;

const int N = 5;
int a[N * N], n = 4 * 4, ans = 0;
int b1[N][5], b2[N][5], b3[N][5]; // 分别记录横行，竖行，四小块

void dfs(int x) {
    if (x > n) {
        ans++;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
            if (i % 4 == 0) {
                cout << '\n';
            }
        }
        cout << '\n';
        return;
    }
    int row = (x - 1) / 4 + 1; // 拿笔算一算
    int col = (x - 1) % 4 + 1;
    int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1; // 我都不知道怎么算出来的
    for (int i = 1; i <= 4; i++) {
        if (b1[row][i] == 0 && b2[col][i] == 0 && b3[block][i] == 0) {
            a[x] = i;
            b1[row][i] = 1;
            b2[col][i] = 1;
            b3[block][i] = 1;
            dfs(x + 1);
            b1[row][i] = 0;
            b2[col][i] = 0;
            b3[block][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfs(1);
    cout << ans << '\n';   
    return 0;
}
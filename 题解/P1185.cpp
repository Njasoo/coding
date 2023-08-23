#include <bits/stdc++.h>
using namespace std;
// id = (1 << (i - 1)) + j - 1
int deleted[10005];
int e[105];
int m, n;
char f[5005][5005];
void dfs(int x, int y, int id, int s) {
    if (s == 0) return;
    if (!deleted[id << 1]) {
        for (int i = 1; i <= e[s]; i++) {
            f[x + i][y - i] = '/';
        }
        f[x + e[s] + 1][y - e[s] - 1] = 'o';
        dfs(x + e[s] + 1, y - e[s] - 1, id << 1, s - 1);
    }
    if (!deleted[id << 1 | 1]) {
        for (int i = 1; i <= e[s]; i++) {
            f[x + i][y + i] = '\\';
        }
        f[x + e[s] + 1][y + e[s] + 1] = 'o';
        dfs(x + e[s] + 1, y + e[s] + 1, id << 1 | 1, s - 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(f, ' ', sizeof(f));
    e[1] = 1;
    for (int i = 1; i <= 20; i++) {
        e[i + 1] = (1 << i) + (1 << (i - 1)) - 1;
    }
    // for (int i = 1; i <= 20; i++) {
    //     cout << e[i] << " ";
    // }
    // cout << '\n';
    // assert(false);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        deleted[(1 << (x - 1)) + y - 1] = 1;
    }
    f[1][e[m] + 1] = 'o';
    dfs(1, e[m] + 1, 1, m - 1);
    for (int i = 1; i <= e[m] + 1; i++) {
        for (int j = 1; j <= e[m + 1] + 1; j++) {
            cout << f[i][j];
        }
        cout << '\n';
    }
    return 0;
}
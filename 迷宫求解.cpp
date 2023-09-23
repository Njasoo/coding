#include <bits/stdc++.h>

using namespace std;

int f[1005][1005];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int tot; // 记录能到达终点的路径总数
bool vis[1005][1005]; // 记录是否访问过这个结点
pair<int, int> path[1005];
int n;
bool finded;

void dfs(int x, int y, int cnt) {
    if (x == n - 1 && y == n - 1) {
        tot++;
        for (int i = 0; i < cnt - 1; i++) {
            if (i % 4 == 0) cout << '\n';
            cout << "[" << path[i].first << ", " << path[i].second << "]--";
        }
        if ((cnt - 1) % 4 == 0) cout << '\n';
        cout << "[" << path[cnt - 1].first << ", " << path[cnt - 1].second << "]--END\n";
        return;
    }
    for (int k = 0; k < 4; k++) {
        int dx = dir[k][0];
        int dy = dir[k][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx > n || ny < 0 || ny > n) continue; // 越界
        if (f[nx][ny] == 1) continue;
        if (vis[nx][ny] == true) continue;
        vis[nx][ny] = true;
        path[cnt] = {nx, ny};
        dfs(nx, ny, cnt + 1);
        vis[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        finded = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> f[i][j];
            }
        }
        vis[0][0] = true;
        path[0] = {0, 0};
        dfs(0, 0, 1);
    }      
    return 0;
}
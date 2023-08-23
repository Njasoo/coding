#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int n;
int f[N][N], temp_f[N][N], vis[N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool bfs(int px, int py) {
    memcpy(temp_f, f, sizeof(temp_f));
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({px, py});
    temp_f[px][py] = 2;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int dx = dir[k][0];
            int dy = dir[k][1];
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (f[nx][ny] == 1) continue;
            if (nx == 1 || nx == n || ny == 1 || ny == n) {
                if (!temp_f[nx][ny]) return false;
            }
            temp_f[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    return true;
}
void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << temp_f[i][j] << " \n"[j == n];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> f[i][j];
        }
    }      
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            // if (!f[i][j]) cerr << "(" << i << "," << j << ")" << " " << bfs(i, j) << endl;
            if (!f[i][j] && bfs(i, j)) {
                // cerr << "Hello" << endl;
                print();
                return 0;   
            }
        }
    }
    return 0;
}
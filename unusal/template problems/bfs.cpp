#include <bits/stdc++.h>

using namespace std;

int f[405][405];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct node {
    int x, y;
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    memset(f, -1, sizeof(f));
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    queue<node> q;
    q.push({x, y});
    f[x][y] = 0;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = u.x + dx[i];
            int yy = u.y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] == -1) {
                f[xx][yy] = f[u.x][u.y] + 1;
                q.push({xx, yy});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", f[i][j]);
        }
        puts("");
    }
    return 0;
}
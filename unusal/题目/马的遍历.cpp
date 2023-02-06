#include <bits/stdc++.h>

using namespace std;

const int N = 405;
int ans[N][N];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct coord {
    int x, y;
};

queue<coord> q;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    memset(ans, -1, sizeof(ans));
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    q.push({sx, sy});
    ans[sx][sy] = 0;
    while (!q.empty()) {
        coord u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x = u.x + dx[i], y = u.y + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && ans[x][y] == -1) {
                ans[x][y] = ans[u.x][u.y] + 1;
                q.push({x, y});
            }
        }
    }   
    for (int i = 1; i <= n; i++, cout << endl) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", ans[i][j]);
        }
    }
    return 0;
}
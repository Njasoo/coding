#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<string> f(n);
    int sx, sy, tx, ty;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'S') {
                sx = i, sy = j;
            } else if (f[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }
    vector<vector<int>> dis;
    auto dijkstra = [&]() {
        dis.assign(n, vector<int>(m, 1e9));
        vector<vector<bool>> vis(n, vector<bool>(m));
        dis[sx][sy] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, sx, sy);
        while (!q.empty()) {
            auto [d, x, y] = q.top();
            q.pop();
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = true;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int w;
                if (isdigit(f[nx][ny])) {
                    w = f[nx][ny] - '0';
                } else {
                    w = 0;
                }
                if (d + w < dis[nx][ny]) {
                    dis[nx][ny] = d + w;
                    q.emplace(d + w, nx, ny);
                }
            }
        }
    };
    dijkstra();
    if (dis[tx][ty] >= h) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
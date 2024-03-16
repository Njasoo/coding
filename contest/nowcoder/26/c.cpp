#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;   
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dis;
    vector<int> dx = {1, 0, 0};
    vector<int> dy = {0, -1, 1};
    auto dijkstra = [&]() -> void {
        dis.assign(n, vector<int>(m, 1e9));
        vector<vector<bool>> vis(n, vector<bool>(m));
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, 0, 0);
        while (!q.empty()) {
            auto [d, x, y] = q.top();
            q.pop();
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = true;
            for (int k = 0; k < 3; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int w = (a[x][y] == a[nx][ny] ? 1 : 2);
                if (d + w < dis[nx][ny]) {
                    dis[nx][ny] = d + w;
                    q.emplace(d + w, nx, ny);
                }
            }
        }
    };
    dijkstra();
    cout << dis[n - 1][m - 1] << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
};

int m, ans[310][310], death[310][310], min_ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<node> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    min_ans = 100000;
    memset(ans, -1, sizeof(ans));
    memset(death, 0x3f, sizeof(death)); // 0x3f 超过1e9
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        auto MIN = [&](int tx, int ty, int tt) {
            if (tx >= 0 && ty >= 0) {
                death[tx][ty] = min(death[tx][ty], tt);
            }
        };
        MIN(x, y, t);
        for (int k = 0; k < 4; k++) {
            MIN(x + dx[k], y + dy[k], t);
        }
    }
    q.push({0, 0});
    ans[0][0] = 0;
    node u = q.front();
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = u.x + dx[k];
            int y = u.y + dy[k];
            if (x >= 0 && y >= 0 && ans[x][y] == -1 && ans[u.x][u.y] + 1 < death[x][y]) {
                q.push({x, y});
                ans[x][y] = ans[u.x][u.y] + 1;
            }
        }
    }
    for (int i = 0; i <= 305; i++) {
        for (int j = 0; j <= 305; j++) {
            if (ans[i][j] != -1 && death[i][j] > 1000) {
                min_ans = min(min_ans, ans[i][j]);
            }
        }
    }
    cout << (min_ans == 100000 ? -1 : min_ans) << '\n';
    return 0;
}
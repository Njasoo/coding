#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    bool flag = false;

    auto dfs = [&](auto self, int x, int y, int pos) -> void {
        if (flag) return;
        if (vis[x][y]) return;
        if (board[x][y] != word[pos]) return;
        if (pos == word.size() - 1) {
            flag = true;
            return;
        }
        vis[x][y] = true;
        for (auto [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            self(self, nx, ny, pos + 1);
        }
        vis[x][y] = false;
    };   

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(dfs, i, j, 0);
            if (flag) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}
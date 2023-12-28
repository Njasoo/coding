#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 25;
int n, m, sx, sy, bx, by, tx, ty, case_no;
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
char temp1[] = {'n', 's', 'e', 'w'};
char temp2[] = {'N', 'S', 'E', 'W'};
bool visb[N][N], visp[N][N];
char f[N][N];
struct Status {
    int _px, _py, _bx, _by;
    string path;
} g_s, g_s_now;
struct Person {
    int _x, _y;
    string path;
} g_p, g_p_now;

bool check(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

bool bfs_person(int start_x, int start_y, int end_x, int end_y) {
    memset(visp, 0, sizeof visp);
    g_p._x = start_x;
    g_p._y = start_y;
    g_p.path = "";
    visp[g_p._x][g_p._y] = 1;
    visp[g_s._bx][g_s._by] = 1; // 箱子的起始位置视作障碍
    queue<Person> q;
    q.push(g_p);
    while (!q.empty()) {
        g_p = q.front();
        q.pop();
        if (g_p._x == end_x && g_p._y == end_y) return 1;
        for (int k = 0; k < 4; k++) {
            int dx = dir[k][0];
            int dy = dir[k][1];
            int nx = g_p._x + dx;
            int ny = g_p._y + dy;
            if (check(nx, ny) && f[nx][ny] != '#' && !visp[nx][ny]) {
                visp[nx][ny] = 1;
                g_p_now._x = nx;
                g_p_now._y = ny;
                g_p_now.path = g_p.path + temp1[k];
                // if (nx == end_x && ny == end_y) return 1;
                q.push(g_p_now);
            }
        }
    }
    return 0;
}

bool bfs_box() {
    memset(visb, 0, sizeof visb);
    g_s._px = sx;
    g_s._py = sy;
    g_s._bx = bx;
    g_s._by = by;
    g_s.path = "";
    visb[bx][by] = 1;
    queue<Status> q;
    q.push(g_s);
    while (!q.empty()) {
        g_s = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int dx = dir[k][0];
            int dy = dir[k][1];
            int n_bx = g_s._bx + dx;
            int n_by = g_s._by + dy;
            int n_px = g_s._bx - dx;
            int n_py = g_s._by - dy;
            if (check(n_bx, n_by) && f[n_bx][n_by] != '#' && check(n_px, n_py) && f[n_px][n_py] != '#' && !visb[n_bx][n_by]) {
                if (bfs_person(g_s._px, g_s._py, n_px, n_py)) {
                    visb[n_bx][n_by] = 1;
                    g_s_now._bx = n_bx;
                    g_s_now._by = n_by;
                    g_s_now._px = g_s._bx;
                    g_s_now._py = g_s._by;
                    g_s_now.path = g_s.path + g_p.path + temp2[k];
                    if (n_bx == tx && n_by == ty) return 1;
                    q.push(g_s_now);
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        // memset(f, '#', sizeof f);
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> f[i][j];
                if (f[i][j] == 'S') {
                    sx = i, sy = j;
                } else if (f[i][j] == 'B') {
                    bx = i, by = j;
                } else if (f[i][j] == 'T') {
                    tx = i, ty = j;
                }
            }
        }
        cout << "Maze #" << ++case_no << '\n';
        if (bfs_box()) cout << g_s_now.path << "\n\n";
        else cout << "Impossible.\n\n";
    }
    return 0;
}
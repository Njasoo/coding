#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 105;
struct Node {
    int x, y;
} id[N];
char f[N][N], g[N][N];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void flip(char& ch) {
    ch = (ch == 'w' ? 'b' : 'w');
}

bool check() {
    int cnt_b = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (g[i][j] == 'b') {
                cnt_b++;
            }
        }
    }
    return (cnt_b == 0 || cnt_b == 16);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> f[i][j];
            idx++;
            id[idx].x = i;
            id[idx].y = j;
        }
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << idx); mask++) {
        int cnt_1 = 0;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                g[i][j] = f[i][j];
            }
        }
        for (int i = 0; i < idx; i++) {
            if (mask >> i & 1) {
                cnt_1++;
                int x = id[i + 1].x;
                int y = id[i + 1].y;
                flip(g[x][y]);
                for (int k = 0; k < 4; k++) {
                    int dx = dir[k][0];
                    int dy = dir[k][1];
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
                    flip(g[nx][ny]);
                }
            }
        }
        if (check()) {
            ans = min(ans, cnt_1);
        }
    }
    if (ans == (int)1e9) {
        cout << "Impossible\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}
#include <stdio.h>

int n, m, tot = 0;
int f[105][105], vis[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = 1;
    if (x == n && y == m) {
        printf("%d\n", ++tot);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d", vis[i][j]);
                if (j != m) putchar(' ');
            }
            puts("");
        }
    } else {
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && f[xx][yy] == 1) {
                dfs(xx, yy);
            }
        }
    }
    vis[x][y] = 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
             scanf("%d", &f[i][j]);
        }
    }
    dfs(1, 1);
    return 0;
}
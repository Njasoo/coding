#include <stdio.h>

struct node {
    int pre, now;
}f[105][105];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &f[i][j].pre);
            f[i][j].now = f[i][j].pre;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int l = j, r = j;
            while (l > 1 && f[i][l - 1].pre == f[i][j].pre) {
                l--;
            }
            while (r < m && f[i][r + 1].pre == f[i][j].pre) {
                r++;
            }
            if (r - l + 1 >= 3) {
                for (int k = l; k <= r; k++) {
                    f[i][k].now = 0;
                }
            }
            int t = i, b = i;
            while (t > 1 && f[t - 1][j].pre == f[i][j].pre) {
                t--;
            }
            while (b < n && f[b + 1][j].pre == f[i][j].pre) {
                b++;
            }
            if (b - t + 1 >= 3) {
                for (int k = t; k <= b; k++) {
                    f[k][j].now = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d", f[i][j].now);
            if (j != m) putchar(' ');
        }
        puts("");
    }
    return 0;
}
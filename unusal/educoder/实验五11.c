#include <stdio.h>

int f[105][105];

int main() {
    int n;
    scanf("%d", &n);
    int start = 1, end = n;
    int cnt = 0;
    while (cnt < n * n) {
        for (int j = start; j <= end; j++) {
            f[start][j] = ++cnt;
        }
        for (int i = start + 1; i <= end; i++) {
            f[i][end] = ++cnt;
        }
        for (int j = end - 1; j >= start; j--) {
            f[end][j] = ++cnt;
        }
        for (int i = end - 1; i >= start + 1; i--) {
            f[i][start] = ++cnt;
        }
        start++, end--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", f[i][j]);
            if (j != n) putchar(' ');
        }
        puts("");
    }
    return 0;
}
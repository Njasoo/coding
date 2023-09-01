#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &f[i][j]);
                if (f[i][j] % 2 == 0) ans += f[i][j];
                else ans -= f[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
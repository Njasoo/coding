#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <functional>
#include <ctime>
#include <cassert>
#include <numeric>
#include <bitset>

using namespace std;

int a[15][15], b[15][15];
int ans[15][15];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", ans[i][j]);
        }
        puts("");
    }
    return 0;
}
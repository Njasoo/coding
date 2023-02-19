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

double f[105][105], g[105][105];
double ans[105][105];

int main() {
    int n, s, m;
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
          scanf("%lf", &f[i][j]);
        }
    }
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lf", &g[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= s; k++) {  
                ans[i][j] += f[i][k] * g[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%.2lf ", ans[i][j]);
        }
        puts("");
    } 
    return 0;
}
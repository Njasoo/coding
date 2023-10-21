#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
int a[N][N], c[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }   
    return 0;
}
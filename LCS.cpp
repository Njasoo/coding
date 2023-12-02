#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
char x[N], y[N];
int c[N][N];
string b[N][N];

void print_LCS(int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == "lu") {
        print_LCS(i - 1, j - 1);
        cout << x[i];
    } else if (b[i][j] == "up") {
        print_LCS(i - 1, j);
    } else {
        print_LCS(i, j - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    cin >> (x + 1) >> (y + 1);
    for (int i = 1; i <= m; i++) {
        c[i][0] = 0;
    }   
    for (int j = 1; j <= n; j++) {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "lu";
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = "up";
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "le";
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }
    print_LCS(m, n);
    return 0;
}
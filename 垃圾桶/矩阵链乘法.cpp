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
int p[N], s[N][N];
ll dp[N][N];

void print_ans(int i, int j) {
    if (i == j) {
        cout << " A_" << i << " ";
    } else {
        cout << "(";
        print_ans(i, s[i][j]);
        print_ans(s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }   
    for (int i = 0; i <= n; i++) {
        cerr << p[i] << " ";
    }
    cerr << endl;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (j > n) break;
            dp[i][j] = 1e18;
            for (int k = i; k < j; k++) {
                ll temp = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[j] * p[k];
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "minimum ans: " << dp[1][n] << '\n';
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= n - (n - i); j--) {
            cout << dp[i][j] << "(" << i << ", " << j << ") ";
        }
        cout << '\n';
    }
    cout << '\n';
    print_ans(1, n);
    return 0;
}
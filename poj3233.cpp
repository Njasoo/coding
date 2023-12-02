#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 35;
int n, m, k;
struct Matrix {
    int f[N][N];
} origin;

void mul(Matrix& A, Matrix B) {
    Matrix temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp.f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                temp.f[i][j] = (temp.f[i][j] + A.f[i][k] * B.f[k][j]) % m;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A.f[i][j] = temp.f[i][j];
        }
    }
}

Matrix power(Matrix base, long long pow) {
    Matrix res;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                res.f[i][j] = 1;
            } else {
                res.f[i][j] = 0;
            }
        }
    }
    while (pow) {
        if (pow % 2) mul(res, base);
        mul(base, base);
        pow /= 2;
    }
    return res;
}

void add(Matrix& A, Matrix B) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A.f[i][j] = (A.f[i][j] + B.f[i][j]) % m;
        }
    }
}

Matrix solve(int now) {
    if (now == 1) {
        return origin;
    }
    if (now % 2 == 1) {
        Matrix temp = power(origin, now);
        Matrix res = solve(now - 1);
        add(res, temp);
        return res;
    } else {
        Matrix temp = power(origin, now / 2);
        Matrix res = solve(now / 2);
        mul(temp, res);
        add(res, temp);
        // cerr << "now = " << now << endl;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cerr << res.f[i][j] << " ";
        //     }
        //     cerr << endl;
        // }
        return res;
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &origin.f[i][j]);
            origin.f[i][j] %= m;
        }
    }
    Matrix ans = solve(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", ans.f[i][j]);
        }
        puts("");
    }
    return 0;
}
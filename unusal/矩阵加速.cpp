#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
const int MOD = 1e9 + 7;
struct Matrix {
    int n, m;
    long long f[5][5];
    Matrix(int _n, int _m) : n(_n), m(_m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = 0;
            }
        }
    }
    Matrix operator*(Matrix &x) {
        Matrix res(n, x.m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x.m; j++) {
                res.f[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x.m; j++) {
                for (int k = 1; k <= m; k++) {
                    res.f[i][j] += f[i][k] * x.f[k][j] % MOD;
                    res.f[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};
Matrix power(Matrix A, long long k) {
    Matrix res(A.n, A.n);
    for (int i = 1; i <= res.n; i++) {
        for (int j = 1; j <= res.m; j++) {
            res.f[i][j] = 0;
        }
    }
    for (int i = 1; i <= res.n; i++) {
        res.f[i][i] = 1;
    }
    while (k) {
        if (k % 2) res = res * A;
        A = A * A;
        k /= 2;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    if (n <= 4) {
        if (n <= 3) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
        return;
    }
    Matrix A(4, 4);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            A.f[i][j] = 0;
        }
    }
    A.f[1][1] = A.f[1][3] = A.f[2][2] = A.f[2][4] = A.f[3][2] = A.f[4][3] = 1;
    A = power(A, n - 4);
    Matrix beg(4, 1);
    beg.f[1][1] = 2;
    beg.f[2][1] = beg.f[3][1] = beg.f[4][1] = 1;
    Matrix ans(4, 1);
    ans = A * beg;
    cout << ans.f[1][1] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
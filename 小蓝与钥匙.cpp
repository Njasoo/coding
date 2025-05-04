#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr<<"\n"

const int N = 105;
ull fac[N], dp1[N], dp2[N];
ull rec(int n);

ull C(int n, int k) {
    int k2 = n - k;
    if (k < k2) {
        swap(k, k2);
    }
    ull res = 1;
    for (int i = k + 1; i <= n; i++) {
        res *= i;
    }
    res /= fac[k2];
    return res;
}

ull rec2(int n) {
    if (dp2[n] != 114514) {
        return dp2[n];
    }
    if (n == 1) {
        return dp2[1] = 1;
    }
    ull res = 0;
    for (int i = 1; i <= n; i++) {
        res += rec(n - i) * C(n, i);
    }
    return dp2[n] = res;
}

ull rec(int n) {
    if (dp1[n] != 114514) {
        return dp1[n];
    }
    if (n == 1) {
        return dp1[1] = 0;
    }
    return dp1[n] = fac[n] - rec2(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 105; i++) {
        dp1[i] = 114514;
        dp2[i] = 114514;
    }
    fac[1] = fac[0] = 1;
    for (int i = 1; i <= 14; i++) {
        fac[i] = fac[i - 1] * i;
    }
    ull ans = 1;
    for (int i = 15; i <= 28; i++) {
        ans *= i;
    }
    ans /= fac[14];
    ans *= rec(14);
    cout << ans << "\n";
    return 0;
}
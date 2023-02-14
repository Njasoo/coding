#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
// ??
int calc(long long x) {
    int res = 0;
    while (x % 10 == 0 && x) {
        x /= 10;
        res++;
    }
    return res;
}
long long power(int a, int b) {
    long long res = 1;
    long long base = a;
    while (b) {
        if (b % 2 == 1) res *= base;
        base *= base;
        b /= 2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    // int cnt_case = 0;
    while (tt--) {
        long long n, m;
        cin >> n >> m;
        int max_0 = calc(n);
        long long ans = n * m;
        for (int i = 0; i <= 29; i++) {
            long long _2 = power(2, i);
            for (int j = 0; j <= 13; j++) {
                long long _5 = power(5, j);
                if (_2 * _5 > m) break;
                long long cnt = n * (m - (m % (_2 * _5)));
                if (calc(cnt) > max_0) {
                    max_0 = calc(cnt);
                    ans = cnt;
                } else if (calc(cnt) == max_0) {
                    ans = max(ans, cnt);
                }
            }
        }
        // cout << "case: " << ++cnt_case << ": ";
        cout << ans << '\n';
    }
    return 0;
}
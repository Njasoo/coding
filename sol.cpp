#include <bits/stdc++.h>
using namespace std;
// x 是a1的倍数，x是b1的约数，根号枚举b1的约数,判断是否符合条件
// 本来打算同时枚举a1的倍数，结果超时了
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        int ans = 0;
        for (long long factor = 1; factor * factor <= b1; factor++) {
            if (b1 % factor == 0) {
                if (__gcd(factor, a0) == a1 && factor * b0 / __gcd(factor, b0) == b1) ans++;
                long long factor2 = b1 / factor;
                if (factor == factor2) break; // 不要重复计算
                if (__gcd(factor2, a0) == a1 && factor2 * b0 / __gcd(factor2, b0) == b1) ans++;
            }
        }
        cout << ans << '\n';
    }       
    return 0;
}
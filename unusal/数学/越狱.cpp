#include <bits/stdc++.h>

using namespace std;

const int MOD = 100003;

long long mypow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long m, n;
    cin >> m >> n;
    long long all = mypow(m, n);
    long long impossible = (m * mypow(m - 1, n - 1)) % MOD;
    cout << (all - impossible + MOD) % MOD << '\n';
    return 0;
}
/*
如果只想得到一种方法, 尝试倒推
例如容斥问题, 就考虑一下对立事件
常见优化时间复杂度方法, 前缀和+二分
*/
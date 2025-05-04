#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

// 将(n / i)相同的合在一起算，时间复杂度sqrt(n) * log(n) ~ 9e5

const i64 MOD = 1e9 + 7;
int n;

int find_r(int x) {
    // 要找到最大的i使得n / i == x
    int lo = 1, hi = n;
    int res = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (n / mid == x) {
            lo = mid + 1;
            res = mid;
        } else if (n / mid < x) {
            hi = mid - 1;
        } else if (n / mid > x) {
            lo = mid + 1;
        }
    }
    return res;
}

i64 power(i64 u, i64 v) {
    i64 res = 1;
    while (v) {
        if (v % 2) {
            res = res * u % MOD;
        }
        u = u * u % MOD;
        v /= 2;
    }
    return res;
}

i64 inv(i64 x) {
    return power(x, MOD - 2);
}

i64 calc(i64 x) {
    return ((x * (x + 1) % MOD) * (2 * x + 1) % MOD) * inv(6) % MOD;
}

void add(i64& u, i64 v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    if (u < 0) {
        u += MOD;
    }
}

i64 sum(i64 u, i64 v) {
    add(u, v);
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    i64 ans = 0;
    for (int i = 1; i <= n; ) {
        int x = n / i;
        int r = find_r(x);
        add(ans, sum(calc(r), -calc(i - 1)) * x % MOD);
        i = r + 1;
    }   
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

i64 k;

i64 calc(i64 d) {
    i64 now = 5;
    i64 res = 0;
    while (now <= d) {
        res += d / now;
        now *= 5;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    i64 lo = 1, hi = 9e18;
    // u64 ans = -1; // 严重错误，无符号数没有负数
    i64 ans = 0;
    while (lo <= hi) {
        // i64 mid = (lo + hi) / 2;
        i64 mid = lo + (hi - lo) / 2; // 防溢出
        if (calc(mid) >= k) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (calc(ans) == k) { // 再检查一次，可能取到比k大的数
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

long long power(long long u, int v) {
    long long res = 1;
    while (v) {
        if (v % 2) res *= u;
        u *= u;
        v /= 2;
    }
    return res;
}

bool check(long long mid, long long base, int need) {
    long long res = 0;
    int now = 1;
    while (power(base, now) <= mid) {
        res += mid / power(base, now);
        now++;
    }
    return res >= need;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long k;
    cin >> k;
    map<long long, int> cnt;
    for (long long i = 2; i * i <= k; i++) {
        while (k % i == 0) {
            cnt[i]++;
            k /= i;
        }
    }
    if (k != 1) {
        cnt[k]++;
    }
    long long ans = 0;
    for (auto [x, y] : cnt) {
        long long cnt = 0;
        long long l = 1, r = 1e18;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid, x, y)) {
                r = mid - 1;
                cnt = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
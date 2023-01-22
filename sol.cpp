#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
long long a[N], b[N];
long long n, m;
bool check(long long mid) {
    memcpy(b, a, sizeof(a));
    sort(b + 1, b + 1 + mid, [&](long long i, long long j) {
        return i > j;
    });
    long long tempm = m;
    for (long long i = 1; i < mid; i += 2) {
        tempm -= max(b[i], b[i + 1]);
    }
    if (mid % 2) tempm -= b[mid];
    if (tempm < 0) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    long long l = 1, r = n;
    long long ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
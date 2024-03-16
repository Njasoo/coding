#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M, K;
    cin >> N >> M >> K;
    i64 L = lcm(N, M);
    i64 lo = min(N, M), hi = 2e18;
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        i64 cnt = mid / N + mid / M - 2 * (mid / L);
        if (cnt >= K) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << hi << '\n';
    return 0;
}
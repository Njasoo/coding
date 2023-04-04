#include <bits/stdc++.h>

using namespace std;

// so the goal is to find exactly one line that doesn't intersect or touch
// each parabola?
// no, misunderstood the problem
// greedy, notice that when k is closer to b, (b - k) ^ 2 is smaller
// b - 2 * sqrt(a * c) < k < b + 2 * sqrt(a * c)
// we can find that the lhs and rhs is near b, so we just have to check
// the smallest k that >= k or the largest k that <= k

const int N = 1e5 + 5;
long long k[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cerr << k[i] << " \n"[i == n];
    // }
    sort(k + 1, k + 1 + n);
    for (int i = 1; i <= m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        // cerr << b - 2 * sqrtl(a * c) << " " << b + 2 * sqrtl(a * c) << endl;
        int l = 1, r = n;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (k[mid] >= b) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // cerr << "pos = " << pos << endl;
        if (pos != -1) {
            // cerr << "k[pos] = " << k[pos] << endl;
            if (b - 2 * sqrtl(a * c) < k[pos] && k[pos] < b + 2 * sqrtl(a * c)) {
                cout << "YES\n";
                cout << k[pos] << "\n";
                continue;
            }
        }
        l = 1, r = n;
        pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (k[mid] <= b) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // cerr << "pos = " << pos << endl;
        // cerr << "k[pos] = " << k[pos] << endl;
        if (pos != -1) {
            if (b - 2 * sqrtl(a * c) < k[pos] && k[pos] < b + 2 * sqrtl(a * c)) {
                cout << "YES\n";
                cout << k[pos] << "\n";
                continue;
            }
        }
        cout << "NO\n";
    }
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
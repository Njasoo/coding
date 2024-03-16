#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    i64 n;
    cin >> n;
    i64 ans = n;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            i64 p = n / i;
            if (p * p > n) {
                ans = min(ans, p);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}
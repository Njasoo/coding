#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) { // pos
        for (int j = 1; j <= n; j++) { // index
            bool flag = true;
            int mx = i * j;
            long long cnt = -mx;
            set<int> s;
            for (int k = 1; k <= n; k++) {
                s.insert(k);
            }
            for (int k = n; k >= 1; k--) { // also index
                auto it = s.upper_bound(mx / k);
                if (it == s.begin()) {
                    flag = false;
                    break;
                }
                it = prev(it);
                if ((*it) * k > mx) {
                    flag = false;
                    break;
                }
                cnt += k * (*it);
                s.erase(it);
            }
            if (flag) {
                ans = max(ans, cnt);
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
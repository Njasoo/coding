#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        const int inf = (int) 1e9;
        int ans = -inf;
        for (int i = 0; i < n; i++) {
            ans = max(ans, a[(i - 1 + n) % n] - a[i]);
        }
        for (int i = 1; i < n; i++) {
            ans = max(ans, a[i] - a[0]);
        }
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[n - 1] - a[i]);
        }
        cout << ans << '\n';
    }   
    return 0;
}
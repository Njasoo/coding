#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int cur = 0;
        vector<int> a(n);
        for (int x = 0; x < k; x++) {
            if (x % 2 == 0) {
                for (int i = x; i < n; i += k) {
                    a[i] = ++cur;
                }
            } else {
                // x + a * k <= n - 1
                // a <= (n - 1 - x) / k
                for (int i = x + (n - 1 - x) / k * k; i >= x; i -= k) {
                    a[i] = ++cur;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}
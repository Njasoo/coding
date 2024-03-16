#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int a[n + 5], b[m + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m, greater<int>());
        long long cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            cnt1 += abs(a[i] - b[i]);
        }
        sort(a + 1, a + 1 + n, greater<int>());
        sort(b + 1, b + 1 + m);
        for (int i = 1; i <= n; i++) {
            cnt2 += abs(a[i] - b[i]);
        }
        cerr << cnt1 << " " << cnt2 << endl;
        cout << max(cnt1, cnt2) << '\n';
    }   
    return 0;
}
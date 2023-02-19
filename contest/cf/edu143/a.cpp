#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                cnt++;
            }
        }
        for (int i = 1; i < m; i++) {
            if (b[i] == b[i - 1]) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << "NO\n";
            continue;
        }
        if (cnt == 1) {
            if (a.back() != b.back()) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}

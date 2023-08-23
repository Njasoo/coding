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
        int m = n * (n - 1) / 2;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 0; i < m; i += --n) {
            cout << b[i] << " ";
        }
        cout << int(1e9) << '\n';
    }
    return 0;
}
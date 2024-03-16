#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> q(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i <= (int) 1e6; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (q[j] < a[j] * i) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cntb = 1E9;
            for (int j = 0; j < n; j++) {
                if (b[j] == 0) continue;
                cntb = min(cntb, (q[j] - i * a[j]) / b[j]);
            }
            ans = max(ans, i + cntb);
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
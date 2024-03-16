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
        pair<int, int> a[n + 5], b[n + 5], c[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i].first;
            c[i].second = i;
        }
        int ans = 0;
        for (int k = 1; k <= 6; k++) {
            priority_queue<pair<int, int>> q1, q2, q3;
            for (int i = 1; i <= n; i++) {
                if (k == 1) q1.push(a[i]), q2.push(b[i]), q3.push(c[i]);
                else if (k == 2) q1.push(b[i]), q2.push(a[i]), q3.push(c[i]);
                else if (k == 3) q1.push(b[i]), q2.push(c[i]), q3.push(a[i]);
                else if (k == 4) q1.push(c[i]), q2.push(b[i]), q3.push(a[i]);
                else if (k == 5) q1.push(c[i]), q2.push(a[i]), q3.push(b[i]);
                else q1.push(a[i]), q2.push(c[i]), q3.push(b[i]);
            }
            if (q2.top().second == q1.top().second) q2.pop();
            while (q3.top().second == q1.top().second || q3.top().second == q2.top().second) {
                q3.pop();
            }
            ans = max(ans, q1.top().first + q2.top().first + q3.top().first);
        }
        cout << ans << '\n';
    }   
    return 0;
}
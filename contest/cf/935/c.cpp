#include <bits/stdc++.h>
using namespace std;

int sum[300005];

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i] == '1');
    }
    int id = -1;
    double ans = 1e9;
    for (int i = 0; i <= n; i++) {
        int le = (i - sum[i]);
        int ri = sum[n] - sum[i];
        if (le >= (i + 1) / 2 && ri >= (n - i + 1) / 2) {
            if (fabs(n / 2.0 - i) < ans) {
                id = i;
                ans = fabs(n / 2.0 - i);
            }
        }
    }
    cout << id << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
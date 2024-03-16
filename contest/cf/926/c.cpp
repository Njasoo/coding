#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, x;
    long long a;
    cin >> k >> x >> a;
    if (a <= x) {
        cout << "NO\n";
        return;
    }
    if (k > x + 1) {
        cout << "YES\n";
        return;
    }
    long long cnt = 1;
    for (int i = 1; i <= x; i++) {
        cnt += cnt / (k - 1) + 1;
        if (cnt > a) {  // 放在回圈里面判断防止溢出
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
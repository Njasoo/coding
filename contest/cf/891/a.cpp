#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a % 2) odd += a;
        else even += a;
    }
    if ((odd - even) % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
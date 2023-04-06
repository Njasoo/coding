#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int b[N], a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    a[1] = b[1];
    for (int i = 2; i < n; i++) {
        if (b[i] > b[i - 1]) a[i] = b[i - 1];
        else a[i] = b[i];
    }
    a[n] = b[n - 1];
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
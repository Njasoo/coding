#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    b = a;
    int highest = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= 5) {
            if (i == 0) {
                a[i]++;
                highest = i;
                break;
            }
            a[i - 1]++;
            highest = i;
        }
    }
    if (highest == n) {
        cout << s << '\n';
    } else {
        if (highest == 0) {
            cout << 1;
            for (int i = 0; i < n; i++) cout << 0;
            cout << '\n';
            return;
        }
        for (int i = highest; i < n; i++) {
            b[i] = 0;
        }
        if (highest >= 1) {
            b[highest - 1]++;
        }
        int now = highest - 1;
        while (b[now] >= 10 && now >= 1) {
            b[now - 1]++;
            b[now] %= 10;
        }
        for (int i = 0; i < n; i++) {
            cout << b[i];
        }
        cout << '\n';
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
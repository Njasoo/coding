#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> sum(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans ^= a[i];
        }
        sum[i + 1] = sum[i] ^ a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            ans ^= sum[r] ^ sum[l - 1];
        } else {
            int g;
            cin >> g;
            cout << (g == 1 ? ans : sum[n] ^ ans) << " ";
        }
    }
    cout << '\n';
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
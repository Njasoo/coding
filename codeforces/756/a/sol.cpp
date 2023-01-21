/**
 *    author:  Njaso
 *    created: 23.06.2022 18:04:04
**/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s = to_string(n);
    int last = s.back() - '0';
    if (last % 2 == 0) {
        cout << 0 << '\n';
        return;
    }
    bool even_exist = false;
    for (int i = 0; i < (int) s.size(); i++) {
        int digit = s[i] - '0';
        if (digit % 2 == 0) {
            even_exist = true;
            break;
        }
    }
    if (!even_exist) {
        cout << -1 << '\n';
        return;
    }
    int first = s[0] - '0';
    if (first % 2 == 0) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
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
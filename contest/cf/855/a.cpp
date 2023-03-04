#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = char(c + 32);
        }
    }
    int p = 0;
    vector<bool> ok(4);
    while (s[p] == 'm') {
        ok[0] = true;
        p++;
    }
    while (s[p] == 'e') {
        ok[1] = true;
        p++;
    }
    while (s[p] == 'o') {
        ok[2] = true;
        p++;
    }
    while (s[p] == 'w') {
        ok[3] = true;
        p++;
    }
    if (ok[0] && ok[1] && ok[2] && ok[3] && p == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
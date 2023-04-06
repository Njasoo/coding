#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    char d;
    cin >> n >> d;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        if (d > s[i] && !flag) {
            flag = true;
            cout << d;
        }
        cout << s[i];
    }
    if (!flag) {
        cout << d;
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = -1;
    char mn = *min_element(s.begin(), s.end());
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == mn) {
            pos = i;
            break;
        }
    }
    s.erase(s.begin() + pos);
    s = mn + s;
    cout << s << '\n';
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
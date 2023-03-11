#include <bits/stdc++.h>
using namespace std;
void solve() {
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
        cout << "YES\n";
        cout << a[0] << "*\n";
        return;
    }
    if (a.back() == b.back()) {
        cout << "YES\n";
        cout << "*" << a.back() << '\n';
        return;
    }
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < b.size() - 1; j++) {
            if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
                cout << "YES\n";
                cout << "*" << a[i] << a[i + 1] << "*\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
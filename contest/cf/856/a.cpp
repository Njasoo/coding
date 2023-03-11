#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<string> temp;
    for (int i = 0; i < 2 * n - 2; i++) {
        string t;
        cin >> t;
        if (t.size() == n / 2) {
            temp.push_back(t);
        }
    }
    reverse(temp[1].begin(), temp[1].end());
    cout << (temp[0] == temp[1] ? "YES" : "NO") << '\n';
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
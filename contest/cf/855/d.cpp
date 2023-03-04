#include <bits/stdc++.h>
using namespace std;
// 玄学做法
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == s[i + 2]) {
            cnt++;
        }
    }
    cout << n - 1 - cnt << '\n';
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
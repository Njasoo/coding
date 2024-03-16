#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    vector<string> a(2);
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
    string ans = a[0] + a[1][n - 1];
    int p = n - 1;
    for (int j = 0; j < n - 1; j++) {
        if (a[1][j] == '0' && a[0][j + 1] == '1') {
            ans = a[0].substr(0, j + 1) + a[1].substr(j);
            p = j;
            break;
        }
    }
    int cnt = 1;
    for (int j = p - 1; j >= 0; j--) {
        if (a[1][j] == a[0][j + 1]) {
            cnt++;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}
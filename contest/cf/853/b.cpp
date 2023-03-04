#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) <<endl
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (s[i] != s[n + 1 - i]) {
            cnt++;
            int j = i;
            while (s[j] != s[n + 1 - j] && j <= n / 2) {
                j++;
            }
            i = j;
        }
    }
    if (cnt > 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
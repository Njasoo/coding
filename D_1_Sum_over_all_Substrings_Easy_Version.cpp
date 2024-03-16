#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int f(string s) {
    int last = -2, res = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1' && i > last + 1) {
            res++;
            last = i + 1;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string t;
        for (int j = i; j < n; j++) {
            t += s[j];
            ans += f(t);
        }
    }
    cout << ans << '\n';
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
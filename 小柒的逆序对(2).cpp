#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e5 + 5;
vector<int> pos[26];
ll cnt[26][26]; // cnt[i][j]: 字母j出现在i后面的情况贡献

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        pos[c].push_back(i);
        // db(c), el;
    }
    // for (int i = 0; i < 3; i++) {
    //     for (int x : pos[i]) {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            int p = upper_bound(all(pos[j]), i) - pos[j].begin();
            ll t = sz(pos[j]) - p;
            // if (i == 1 && j == 1) {
            //     db(sz(pos[j])), db(p), el;
            // }
            cnt[c][j] += t;
        }
    }
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         char c1 = char(i + 'a');
    //         char c2 = char(j + 'a');
    //         db(c1), db(c2), db(cnt[i][j]), el;
    //     }
    // }
    while (q--) {
        string r;
        cin >> r;
        ll ans = 0;
        for (int i = 0; i < sz(r) - 1; i++) {
            for (int j = i + 1; j < sz(r); j++) {
                int c1 = r[i] - 'a';
                int c2 = r[j] - 'a';
                // db(cnt[c2][c1]), db(c1), db(c2), el;
                ans += cnt[c2][c1];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
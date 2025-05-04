#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define pb push_back
#define len(x) int(x.size())
using i64 = long long;
using namespace std;

void solve() {
    string S;
    cin >> S;
    vector<int> pos;
    for (int i = 0; i < len(S); i++) {
        if (S[i] == '?') {
            pos.pb(i);
        }
    }
    auto calc = [&](const string& s) {
        i64 res = 0, cntl = 0, cntr = 0;
        for (int i = 0; i < len(s); i++) {
            if (s[i] == 'o') {
                cntr++;
            }
        }
        for (int i = 0; i < len(s); i++) {
            if (s[i] == 'o') {
                cntl++;
                cntr--;
            } else if (s[i] == 'v') {
                res += cntl * cntr;
            }
        }
        return res;
    };
    i64 ans = 0;
    {
        string t = S;
        for (int p : pos) {
            t[p] = 'o';
        }
        ans = max(ans, calc(t));
    }
    for (int i = 0; i < len(pos); i++) {
        for (int j = i; j < len(pos); j++) {
            string t = S;
            for (int k = 0; k < len(pos); k++) {
                if (k >= i && k <= j) {
                    t[pos[k]] = 'v';
                } else {
                    t[pos[k]] = 'o';
                }
            }
            ans = max(ans, calc(t));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }   
    return 0;
}
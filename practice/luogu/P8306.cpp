#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 3e6 + 5;
int tr[N][130], cnt[N];
int idx;
void insert(string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int to = s[i];
        if (!tr[p][to]) tr[p][to] = ++idx;
        p = tr[p][to];
        cnt[p]++;
    }
}
int query(string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int to = s[i];
        if (!tr[p][to]) return 0;
        p = tr[p][to];
    }
    return cnt[p];
}
void init() {
    for (int i = 0; i <= idx; i++) {
        cnt[i] = 0;
        for (int j = 0; j < 130; j++) {
            tr[i][j] = 0;
        }
    }
    idx = 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        init();
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            insert(s);
        }
        while (q--) {
            string t;
            cin >> t;
            cout << query(t) << '\n';
        }
    }
    return 0;
}
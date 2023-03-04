#include <bits/stdc++.h>
using namespace std;
// 无语，还有字符数不一致的情况
const int N = 2e5 + 5;
int f[N];
int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(y)] = find(x);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
bool check(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (!check(s, t)) {
        cout << "NO\n";
        return;
    }
    s = ' ' + s, t = ' ' + t;
    map<char, vector<int>> pos;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        pos[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i + k <= n) merge(i, i + k);
        if (i + k + 1 <= n) merge(i, i + k + 1);
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == s[i]) continue;
        bool flag = 0;
        for (auto x : pos[s[i]]) {
            if (same(i, x)) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
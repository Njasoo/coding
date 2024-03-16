#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    vector<i64> s1(n + 1), s2(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        s1[i + 1] = s1[i] + c[i];
        s2[i + 1] = s2[i] + (c[i] == 1 ? 2 : 1);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (r - l == 1 || s2[r] - s2[l] > s1[r] - s1[l]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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
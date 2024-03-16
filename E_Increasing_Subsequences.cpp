#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
long long l, r;

void rec(long long x) {
    if (x == 2) {
        ans.push_back(0);
    } else if (x % 2 == 1) {
        rec(x - 1);
        ans.push_back(--l);
    } else {
        rec(x / 2);
        ans.push_back(++r);
    }
}

void solve() {
    long long x;
    cin >> x;
    ans.clear();
    l = 0, r = 0;
    rec(x);
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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
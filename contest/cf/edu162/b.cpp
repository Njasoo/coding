#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> t(n);
    i64 tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i].second;
        tot += t[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i].first;
    }
    sort(t.begin(), t.end(), [&](auto i, auto j) {
        return abs(i.first) < abs(j.first);
    });
    i64 cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += t[i].second;
        if (cnt / k >= abs(t[i].first)) {
            if (cnt / k == abs(t[i].first) && cnt % k == 0) {
                continue;
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
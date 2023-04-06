#include <bits/stdc++.h>

using namespace std;

// just base-9
// 4->5, 5->6, 6->7, ...

void solve() {
    long long k;
    cin >> k;
    vector<int> ans;
    while (k) {
        int cnt = k % 9;
        if (cnt >= 4) cnt++;
        ans.push_back(cnt);
        k /= 9;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
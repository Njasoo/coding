#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 25;
int a[N];

void solve() {
    int n;
    cin >> n;
    int mxa = -1e9, mxpos = -1;
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            flag = 1;
        }
        if (a[i] > mxa) {
            mxa = a[i];
            mxpos = i;
        }
    }
    vector<pair<int, int>> ans;
    if (!flag) {
        for (int i = n - 1; i >= 1; i--) {
            while (a[i] > a[i + 1]) {
                a[i] += a[i + 1];
                ans.push_back({i, i + 1});
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << " " << y << '\n';
        }
        return;
    }
    a[1] += mxa;
    ans.push_back({1, mxpos});
    for (int i = 2; i <= n; i++) {
        while (a[i] < a[i - 1]) {
            ans.push_back({i, i - 1});
            a[i] += a[i - 1];
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// 为什么我看不懂题目
const int N = 2e5 + 5;
int c[N], cnt[N];
void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n, k;
    cin >> n >> k;
    vector<int> pos1, posn;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cnt[c[i]]++;
    }
    if (c[1] == c[n]) {
        if (cnt[c[1]] >= k) { // 考虑能不能直接跳到终点
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == c[1]) {
            pos1.push_back(i);
        }
        if (c[i] == c[n]) {
            posn.push_back(i);
        }
    }
    if (cnt[c[1]] < k || cnt[c[n]] < k) {
        // cerr << "NO1" << endl;
        cout << "NO\n";
        return;
    }
    if (pos1[k - 1] < posn[posn.size() - k]) {
        cout << "YES\n";
    } else {
        // cerr << "NO2" << endl;
        cout << "NO\n";
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
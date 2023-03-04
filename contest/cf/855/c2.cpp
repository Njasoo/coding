#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    priority_queue<int> q;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a) {
            q.push(a);
        } else {
            if (q.size()) {
                ans += q.top();
                q.pop();
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
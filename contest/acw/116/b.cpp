#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> t(n); // (start, spending time, end time)
    for (int i = 0; i < n; i++) {
        cin >> t[i][0] >> t[i][1];
        t[i][2] = t[i][0] + t[i][1];
    }
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> ans(n);
    for (int i = 0; i < k; i++) {
        q.push(t[i][2]);
        ans[i] = t[i][2];
    }
    int id = k;
    while (!q.empty()) {
        int fastest_end_time = q.top();
        q.pop();
        if (id == n) break;
        int end_time;
        if (t[id][0] >= fastest_end_time) {
            end_time = t[id][2];
        } else {
            end_time = fastest_end_time + t[id][1];
        }
        ans[id] = end_time;
        id++;
        q.push(end_time);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
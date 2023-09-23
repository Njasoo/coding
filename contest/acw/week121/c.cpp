#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), cost(n), b(m), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
        cost[i] = i / k + 1;
    }      
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << cost[i] << " \n"[i == n - 1];
    // }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += cost[pos[b[i]]];
        if (pos[b[i]] == 0) continue;
        int pos_b = pos[b[i]];
        int pos_pre_b = pos[b[i]] - 1;
        pos[a[pos[b[i]] - 1]]++;
        pos[b[i]]--;
        swap(a[pos_b], a[pos_pre_b]);
    }
    cout << ans << '\n';
    return 0;
}
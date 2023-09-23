#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), din(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        din[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (din[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        int v = a[u]; // 出边
        if (--din[v] == 0) {
            q.push(v);
        }
    }
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (din[i] == 0 || vis[i]) continue;
        int u = i;
        vector<int> cycle;
        int min_cost = 1e9, pos = -1;
        while (!vis[u]) {
            vis[u] = true;
            cycle.push_back(u);
            if (c[u] < min_cost) {
                min_cost = c[u];
                pos = cycle.size() - 1;
            }
            int v = a[u];
            u = v;
        }
        for (int j = 0; j < (int) cycle.size(); j++) {
            ans.push_back(cycle[(pos + 1 + j) % cycle.size()]);
        }
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] + 1 << " \n"[i == (int) ans.size() - 1];
    }
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
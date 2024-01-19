#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), c(n), in(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            g[i].push_back(a[i]);
            in[a[i]]++;
            g[a[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = a[u];
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    return 0;
}
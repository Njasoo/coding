#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        p[i].push_back(l);
        p[i].push_back(r);
    }   
    vector<int> depth(n);
    queue<int> q;
    q.push(0);
    depth[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : p[u]) {
            if (v == -1) continue;
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << depth[i] << " \n"[i == n - 1];
    }
    return 0;
}
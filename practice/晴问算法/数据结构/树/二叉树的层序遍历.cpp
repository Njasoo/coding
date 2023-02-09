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
    queue<int> q;
    q.push(0);
    vector<int> ans(1, 0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : p[u]) {
            if (v == -1) continue;
            ans.push_back(v);
            q.push(v);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
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
        int u, v;
        cin >> u >> v;
        p[i].push_back(u);
        p[i].push_back(v);
    }   
    vector<int> ans;
    function<void(int)> dfs = [&](int u) {
        if (u == -1) return;
        if (p[u][0] == -1 && p[u][1] == -1) return;
        dfs(p[u][0]);
        dfs(p[u][1]);
        swap(p[u][0], p[u][1]);
    };
    function<void(int)> pre = [&](int u) {
        if (u == -1) return;
        if (u != -1) ans.push_back(u);
        if (p[u][0] != -1) pre(p[u][0]);
        if (p[u][1] != -1) pre(p[u][1]);
    };
    function<void(int)> mid = [&](int u) {
        if (u == -1) return;
        if (p[u][0] != -1) mid(p[u][0]);
        if (u != -1) ans.push_back(u);
        if (p[u][1] != -1) mid(p[u][1]);
    };
    dfs(0);
    pre(0);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    ans.clear();
    mid(0);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
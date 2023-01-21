#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;
int n, a, b, ans = inf;
int k[205];
bool vis[205];

void dfs(int f, int cnt) {
    vis[f] = 1;
    if (f == b) {
        ans = min(ans, cnt);
    } else if (cnt < ans) { // 省时间
        if (!vis[f + k[f]]) {
            dfs(f + k[f], cnt + 1);
        }
        if (f - k[f] >= 1 && !vis[f - k[f]]) {
            dfs(f - k[f], cnt + 1);
        }
    }
    vis[f] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    dfs(a, 0);
    cout << (ans == inf ? -1 : ans) << '\n';    
    return 0;
}
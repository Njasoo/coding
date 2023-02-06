#include <bits/stdc++.h>

using namespace std;

int n, ans[15], vis[15];

void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                ans[k] = i;
                dfs(k + 1);
                vis[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
int n, r, last, idx;
int a[25], ans[25];
bool vis[25];
void dfs(int k) {
    if (k == r + 1) {
        for (int i = 1; i <= r; i++) {
            cout << setw(3) << ans[i];
        }
        cout << '\n';
        return;
    }
    for (int i = last + 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[k] = a[i];
            int temp_last = last;
            last = i;
            dfs(k + 1);
            last = temp_last;
            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for (int i = 1; i <= n; i++) a[i] = i;
    dfs(1);
    return 0;
}
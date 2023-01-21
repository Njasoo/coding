#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N], ans[N];

void dfs(int l, int r, int depth) {
    if (l > r) {
        return;
    }
    int mx = 0, pos = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] > mx) {
            mx = a[i];
            pos = i;
        }
    }
    ans[pos] = depth;
    dfs(l, pos - 1, depth + 1);
    dfs(pos + 1, r, depth + 1);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, n, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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
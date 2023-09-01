#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], ans[N];
bool vis[N];

void solve() {
    int n, k;
    cin >> n >> k;
    memset(vis, 0, sizeof(vis));
    // a[0]是MEX
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            a[0] = i;
            break;
        }
    }
    // n + 1为周期
    k %= n + 1;
    for (int i = 1 - k; i <= 1 - k + (n - 1); i++) {
        if (i < 0) {
            cout << a[i + n + 1] << " ";
        } else {
            cout << a[i] << " ";
        }
    }
    std::cout << '\n';
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
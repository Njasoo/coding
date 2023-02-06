#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int now = 0;
int a[N], b[N], ans[N];
long long curb[N];
vector<int> p[N];

void dfs(int u, long long suma) {
    if (u != 1) {
        int l = 0, r = now;
        curb[now] = curb[now - 1] + b[u];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (curb[mid] <= suma) {
                ans[u] = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    for (int v : p[u]) {
        now++;
        dfs(v, suma + a[v]);
        now--;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        int pt;
        cin >> pt >> a[i] >> b[i];
        p[pt].push_back(i);
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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
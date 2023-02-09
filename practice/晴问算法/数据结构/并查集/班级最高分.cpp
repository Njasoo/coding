#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
int f[N], s[N];
int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (s[x] > s[y]) f[y] = x;
    else f[x] = y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            ans.push_back(s[i]);
        }
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
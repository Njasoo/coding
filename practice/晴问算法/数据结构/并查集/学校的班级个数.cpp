#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
int f[N];
int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    f[y] = x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;   
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) ans++;
    }
    cout << ans << '\n';
    return 0;
}
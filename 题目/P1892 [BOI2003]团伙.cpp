#include <bits/stdc++.h>

using namespace std;

int f[2005];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    iota(f + 1, f + 1 + 2 * n, 1);
    for (int i = 0; i < m; i++) {
        char opt;
        int p, q;
        cin >> opt >> p >> q;
        if (opt == 'F') {
            f[find(p)] = find(q);
        } else {
            f[find(p + n)] = find(q); // p + n是p的補集, 不需要具體知道敵人是誰
            f[find(q + n)] = find(p);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ull=unsigned long long;

#define vt vector
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

vt<pair<int, int>> ans;

void dfs(int len, int cx, int cy, int x, int y) {
    if (len==1) return;
    int d=len/2;
    if (cx<x+d && cy<y+d) {
        ans.pb(mp(x+d, y+d));
        dfs(d, cx, cy, x, y);
    }
    else {
        dfs(d, x+d-1, y+d-1, x, y);
    }
    if (cx<x+d && cy>=y+d) {
        ans.pb(mp(x+d, y+d-1));
        dfs(d, cx, cy, x, y+d);
    }
    else {
        dfs(d, x+d-1, y+d, x, y+d);
    }
    if (cx>=x+d && cy<y+d) {
        ans.pb(mp(x+d-1, y+d));
        dfs(d, cx, cy, x+d, y);
    }
    else {
        dfs(d, x+d, y+d-1, x+d, y);
    }
    if (cx>=x+d && cy>=y+d) {
        ans.pb(mp(x+d-1, y+d-1));
        dfs(d, cx, cy, x+d, y+d);
    }
    else {
        dfs(d, x+d, y+d, x+d, y+d);
    }
}

bool cmp(pair<int, int> i, pair<int, int> j) {
    if (i.first==j.first) return i.second<j.second;
    return i.first<j.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, cx, cy;
    cin >> k >> cx >> cy;
    dfs(1<<k, cx, cy, 1, 1);
    sort(all(ans));
    for (int i=0; i<sz(ans); i++) {
        cout << ans[i].fi << " " << ans[i].se << '\n';
    }
    return 0;
}

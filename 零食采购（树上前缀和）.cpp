#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N=1e5+5;
int c[N], dep[N], fa[N], up[N][21], cnt[N][21];
vector<int> adj[N];

void dfs(int u) {
    for (int i=1; i<=20; i++) {
        cnt[u][i]=cnt[up[u][0]][i];
    }
    cnt[u][c[u]]++;
    for (int v : adj[u]) {
        if (v==up[u][0])
            continue;
        up[v][0]=u;
        dep[v]=dep[u]+1;
        for (int j=1; j<21; j++)
            up[v][j]=up[up[v][j-1]][j-1];
        dfs(v);
    }
}

int LCA(int a, int b) {
    if (dep[a]<dep[b])
        swap(a, b);
    int k=dep[a]-dep[b];
    for (int j=0; j<21; j++)
        if (k>>j&1)
            a=up[a][j];
    if (a==b)
        return a;
    for (int j=20; j>=0; j--) {
        while (up[a][j]!=up[b][j]) {
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        int s, t;
        cin >> s >> t;
        ll ans=0;
        int lca=LCA(s, t);
        for (int i=1; i<=20; i++) {
            int x=cnt[s][i]+cnt[t][i]-2*cnt[lca][i]+(c[lca]==i);
            ans+=(x!=0);
        }
        cout << ans << "\n";
    }
    return 0;
}
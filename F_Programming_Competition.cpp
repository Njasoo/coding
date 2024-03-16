#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr<<#x<<"="<<(x)<< " "
#define el cerr<<endl

const int N=2e5+5;
vector<int> g[N];
int siz[N];

void dfs1(int u) {
    siz[u]=1;
    for (int v:g[u]) {
        dfs1(v);
        siz[u]+=siz[v];
    }
}

int dfs(int u) {
    int mx=0;
    for (int v:g[u]) {
        mx=max(mx, siz[v]);
    }
    if (mx>siz[u]-1-mx) {
        for (int v:g[u]) {
            if (siz[v]==mx) {
                int res=dfs(v);
                // 内部匹配的+贪心的与子树外的结点匹配
                return res+min((siz[u]-1-2*res)/2, siz[u]-1-mx);
            }
        }
    }
    return (siz[u]-1)/2;
}

void solve(int test_no) {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) g[i].clear();
    for (int i=2; i<=n; i++) {
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    dfs1(1);
    cout<<dfs(1)<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    for (int i=1; i<=tt; i++) {
        solve(i);
    }
    return 0;
}
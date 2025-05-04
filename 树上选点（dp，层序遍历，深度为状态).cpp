#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define ts cerr<<"hi "
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define endl '\n'

const int N=2e5+5;
ll dp[N][2],dp2[N][2],a[N];
vector<int> adj[N],g[N];
int n,f[N];

void dfs(int u,int dep)
{
    g[dep].push_back(u);
    for(int v:adj[u])dfs(v,dep+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>f[i];
        adj[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    for(int i=n;i>=1;i--)
    {
        dp2[i][0]=max(dp2[i+1][1],dp2[i+1][0]);
        for(int u:g[i])
        {
            dp[u][0]=dp2[i][0];
            dp[u][1]=max(dp[u][1],a[u]);
            for(int v:g[i+1])
            {
                if(f[v]==u)
                {
                    dp[u][1]=max(dp[u][1],a[u]+dp[v][0]);
                    continue;
                }
                dp[u][1]=max(dp[u][1],a[u]+max(dp[v][0],dp[v][1]));
            }
            dp2[i][1]=max(dp2[i][1],dp[u][1]);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     if(g[i].size())
    //     {
    //         db(i);
    //         for(int v:g[i])cout<<v<<" ";
    //         cout<<endl;
    //     }
    // }
    cout<<max(dp[1][0],dp[1][1])<<endl;
    return 0;
}
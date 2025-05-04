#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N=1005;
const ll MOD=1e9+7;
//dp1[i][j]: 前i个，容积为j的最大值
//dp2[i][j]: 前i个，容积为j的最大值的方案数
ll dp1[N][N],dp2[N][N],v[N],w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp2[i][j]=1; //一开始啥也没装，每个背包价值都是0,啥也不装就是一种方案
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp2[i][j]=dp2[i-1][j];
            dp1[i][j]=dp1[i-1][j];
            if(j>=v[i])
            {
                if(dp1[i-1][j-v[i]]+w[i]>dp1[i][j])
                {
                    dp1[i][j]=dp1[i-1][j-v[i]]+w[i];
                    dp2[i][j]=dp2[i-1][j-v[i]];
                }
                else if(dp1[i-1][j-v[i]]+w[i]==dp1[i][j])
                {
                    (dp2[i][j]+=dp2[i-1][j-v[i]])%=MOD;
                }
            }
        }
    }
    cout<<dp2[n][m]<<'\n';
    return 0;
}
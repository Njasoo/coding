#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// p[i]为第i头牛上车的概率，ans = sigma(p[i])
// 第i头牛上车的概率：它在所有的排列当中可能是任何一个位置，假设它现在是第k头牛
// 那么就要计算前k-1头总重量<=p-a[i]的概率
const int N = 55;
ll dp[N][55][55],C[N][N],a[N],b[N];
//dp[i][j][k]: 前i个选出k个，总重量为j的方案数

void init()
{
    C[0][0]=1;
    for(int i=1;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int p;
    cin>>p;
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        // int idx=0;
        // for(int j=1;j<=n;j++)
        // {
        //     if(j!=i)b[++idx]=a[j];
        // }
        dp[0][0][0]=1;
        for(int j=1;j<=n;j++)
        {
            for(int w=0;w<=p;w++)
            {
                for(int k=0;k<=j;k++)
                {
                    dp[j][w][k]=dp[j-1][w][k];
                    // if(w-b[j]>=0 && k-1>=0) dp[j][w][k]+=dp[j-1][w-b[j]][k-1];
                    if(w-a[j]>=0 && k-1>=0 && j!=i) dp[j][w][k]+=dp[j-1][w-a[j]][k-1];
                }
            }
        }
        double pi=0;
        for(int j=1;j<=n;j++)
        {
            double qj=0;
            // ll cnt=0;
            for(int w=0;w<=p-a[i];w++)
            {
                // db(dp[n-1][w][j-1]),el;
                qj+=1.0*dp[n][w][j-1]/C[n-1][j-1];
                // cnt+=dp[n][w][j-1];
            }
            pi+=1.0/n*qj;
        }
        ans+=pi;
    }
    printf("%.20lf\n",ans);
    return 0;
}
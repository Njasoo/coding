#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
long long d[1000005];
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        d[a]++;
        d[b+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        d[i]+=d[i-1];
        if(d[i]!=1)
        {
            cout<<i<<" "<<d[i]<<'\n';
            return 0;
        }
    }
    cout<<"OK\n";
    return 0;
}
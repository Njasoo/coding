#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MOD=998244353;
pair<double,double> t[1000005];
bool cmp(pair<double,double> i,pair<double,double> j)
{
    return i.first<j.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    double d;
    cin>>d;
    for(int i=1;i<=n;i++)
    {
        double x,a;
        cin>>x>>a;
        t[i].first=x-a/2,t[i].second=x+a/2;
    }
    sort(t+1,t+1+n,cmp);
    int ans=2;
    for(int i=2;i<=n;i++)
    {
        if(t[i].first-t[i-1].second>d)ans+=2;
        else if(t[i].first-t[i-1].second==d)ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
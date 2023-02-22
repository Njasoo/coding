#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MOD=998244353;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x;
    cin>>x;
    long long now=0;
    if(x<0)x=-x;
    for(int i=0;;i++)
    {
        now+=i;
        if((now-x)>=0&&(now-x)%2==0)
        {
            cout<<i<<'\n';
            break;
        }
    }   
    return 0;
}
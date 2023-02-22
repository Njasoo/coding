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
    int flag1=0,flag2=0;
    map<pair<int,int>,int> hs;
    for(int i=1;i<=4;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(hs[{a,c}])
        {
            flag1=1;
        }
        if(hs[{b,d}])
        {
            flag2=1;
        }
    }
    return 0;
}
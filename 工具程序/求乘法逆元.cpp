#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long exgcd(long long a,long long b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long d=exgcd(b,a%b);
    long long prex=x;
    x=y;
    y=prex-a/b*y;
    return d;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b;
    cin>>a>>b;
    exgcd(a,b);
    x=(x%b+b)%b;
    cout<<x<<'\n';
    return 0;
}
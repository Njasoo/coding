#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define LOG 20
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

int n,m,i1,j1,i2,j2,ans;
bool mark;
map<pair<int,int>,bool> vis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        vis.clear();
        mark=0;
        ans=0;
        cin>>n>>m>>i1>>j1>>i2>>j2;
        string s;
        cin>>s;
        int s1=1,s2=1;
        if(s[0]=='U') s1=-1;
        if(s[1]=='L') s2=-1;
        int nowx=i1,nowy=j1;
        int cnt=0;
        while(cnt<100000)
        {
            cnt++;
            if(s1==1 && s2==1)
            {
                if(i2-nowx==j2-nowy && i2-nowx>=0)
                {
                    mark=1;
                    break;
                }
                else
                {
                    int k=min(n-nowx,m-nowy);
                    ans++;
                    if(n-nowx<m-nowy) s1*=-1;
                    else if(n-nowx>m-nowy) s2*=-1;
                    else s1*=-1,s2*=-1;
                    nowx+=k,nowy+=k;
                }
            }
            else if(s1==1 && s2==-1)
            {
                // db(i2-nowx);
                // db(nowy-j2);
                if(i2-nowx==nowy-j2 && i2-nowx>=0)
                {
                    mark=1;
                    break;
                }
                else
                {
                    int k=min(n-nowx,nowy-1);
                    ans++;
                    if(n-nowx<nowy-1) s1*=-1;
                    else if(n-nowx>nowy-1) s2*=-1;
                    else s1*=-1,s2*=-1;
                    nowx+=k,nowy-=k;
                }
            }
            else if(s1==-1 && s2==1)
            {
                //k要非负
                if(nowx-i2==j2-nowy && nowx-i2>=0)
                {
                    mark=1;
                    break;
                }
                else
                {
                    int k=min(nowx-1,m-nowy);
                    // db(k);
                    ans++;
                    if(nowx-1<m-nowy) s1*=-1;
                    else if(nowx-1>m-nowy) s2*=-1;
                    else s1*=-1,s2*=-1;
                    // db(s1);
                    // db(s2);
                    nowx-=k,nowy+=k;
                    // db(nowx);
                    // db(nowy);
                }
            }
            else if(s1==-1 && s2==-1)
            {
                if(nowx-i2==nowy-j2 && nowx-i2>=0)
                {
                    mark=1;
                    break;
                }
                else
                {
                    int k=min(nowx-1,nowy-1);
                    ans++;
                    if(nowx-1<nowy-1) s1*=-1;
                    else if(nowx-1>nowy-1) s2*=-1;
                    else s1*=-1,s2*=-1;
                    nowx-=k,nowy-=k;
                }
            }
        }
        if(mark) cout<<ans<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
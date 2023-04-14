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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    long long int ans=0;
    // int pos=-1;
    for(int i=0;i<n-1;i++)
    {
        int p1=i,p2=i+1;
        long long int cnt=2;
        char stdl=s[p1],stdr=s[p2];
        if(stdl=='w' && stdr=='w')
        {
            //四种情况
            //rr
            cnt=2;
            stdl='r',stdr='r';
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }       
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }             
            //rb
            p1=i,p2=i+1;
            stdl='r',stdr='b';
            cnt=2;
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }   
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }    
            //br
            p1=i,p2=i+1;
            cnt=2;
            stdl='b',stdr='r';
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }       
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            //bb
            p1=i,p2=i+1;
            cnt=2;
            stdl='b',stdr='b';
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }       
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            continue;
        }
        else if(stdl=='w')
        {
            //r
            stdl='r';
            p1=i,p2=i+1;
            cnt=2;
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            //b
            stdl='b';
            p1=i,p2=i+1;
            cnt=2;
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            continue;
        }
        else if(stdr=='w')
        {
            //r
            stdr='r';
            p1=i,p2=i+1;
            // db(p1);
            // db(p2);
            cnt=2;
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            //b
            stdr='b';
            cnt=2;
            p1=i,p2=i+1;
            while(((p1-1)%n+n)%n!=p2)
            {
                p1--;
                if(p1<0) p1=n-1;
                if(s[p1]!=stdl && s[p1]!='w')
                {
                    p1++;
                    if(p1>=n) p1=0;
                    break;
                }
                cnt++;
            }
            // db(cnt);
            // db(p1);
            // db(p2);
            while((p2+1)%n!=p1)
            {
                p2++;
                if(p2>=n) p2=0;
                if(s[p2]!=stdr && s[p2]!='w')
                {
                    p2--;
                    if(p2<0) p2=n-1;
                    break;
                }
                cnt++;
            }
            // db(cnt);
            if(cnt>ans)
            {
                ans=cnt;
                // pos=i;
            }
            continue;
        }
        while(((p1-1)%n+n)%n!=p2)
        {
            p1--;
            if(p1<0) p1=n-1;
            if(s[p1]!=stdl && s[p1]!='w')
            {
                p1++;
                if(p1>=n) p1=0;
                break;
            }
            cnt++;
        }
        while((p2+1)%n!=p1)
        {
            p2++;
            if(p2>=n) p2=0;
            if(s[p2]!=stdr && s[p2]!='w')
            {
                p2--;
                if(p2<0) p2=n-1;
                break;
            }
            cnt++;
        }
        if(cnt>ans)
        {
            ans=cnt;
            // pos=i;
        }
    }
    cout<<ans<<'\n';
    // db(pos);
    return 0;
}
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

int cnt[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        memset(cnt,0,sizeof(cnt));
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        if(s[0]==s[3])
        {
            cout<<"-1\n";
            continue;
        }
        if((s[0]==s[1] && s[1]==s[2] && s[3]!=s[0]) || (s[0]!=s[1] && s[1]==s[2] && s[2]==s[3])) cout<<6<<'\n';
        else cout<<4<<'\n';
    }   
    return 0;
}
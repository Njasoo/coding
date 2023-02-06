#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int cnt;
        cin>>cnt;
        int ans=0,one=1;
        while(cnt)//只需要问cnt次
        {
            cout<<"- "<<one<<endl;
            int res;
            cin>>res;
            int diff=res-cnt;
            ans|=1<<(diff+1);
            one=(1<<(diff+1));
            cnt--;
        }
        cout<<"! "<<ans<<endl;
    }       
    return 0;
}
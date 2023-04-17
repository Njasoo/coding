#include<iostream>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    if(a<b)swap(a,b);
    while(a!=b)
    {
        if(a>b)
        {
            if(b==0)
            {
                ans--;
                break;
            }
            if(b==1)
            {
                ans+=a-1;
                break;
            }
            ans+=a/b;
            a%=b;
        }
        else
        {
            if(a==0)
            {
                ans--;
                break;
            }
            if(a==1)
            {
                ans+=b-1;
                break;
            }
            ans+=b/a;
            b%=a;
        }
        // cerr<<a<<" "<<b<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
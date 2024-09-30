#include<bits/stdc++.h>

using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        if(k==1){
            cout<<n<<'\n';
            continue;
        }
        if(k>n){
            cout<<n<<'\n';
        }
        else if(k==n){
            cout<<"1\n";
        }
        else{
            int ans=0;
            while(n){
                ll now=1;
                while(now<=n){
                    if(now*k>n){
                        break;
                    }
                    now*=k;
                }
                n-=now;
                ans++;
            }
            cout<<ans<<'\n';
        }
    }   
    return 0;
}
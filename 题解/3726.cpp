#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<endl
const ll INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;
    cin>>n;
    int a;
    cin>>a;
    int cnt=a%2,flag=1;
    for(int i=2;i<=n;i++){
        cin>>a;
        if(a%2!=cnt)flag=0;
    }
    if(flag)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long ll;

const int N=1e5+5;
ll sum,a[N],b[N];
int n;

bool check(ll x){
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        b[i]-=x;
    }
    ll temp1=x;
    for(int i=1;i<=n;i++){
        if(temp1==0){
            break;
        }
        if(i==n){
            ll t=min(temp1,b[i]);
            if(t<=0)continue;
            temp1-=t;
            b[i]-=t;
        }
        else{
            ll t=min(b[i],b[i+1]);
            if(t<=0)continue;
            temp1-=t;
            b[i]-=t;
            b[i+1]-=t;
        }
    }
    ll temp2=x;
    for(int i=1;i<=n;i++){
        if(temp2==0)break;
        if(b[i]>0){
            ll t=min(temp2,b[i]);
            b[i]-=t;
            temp2-=t;
        }
    }
    for(int i=1;i<=n;i++){
        if(temp1==0){
            break;
        }
        if(b[i]>0){
            ll t=min(temp1,b[i]);
            b[i]-=t;
            temp1-=t;
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]>0){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;   
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll lo=1,hi=1e18;
    ll ans=-1;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}
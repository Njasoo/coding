#include<bits/stdc++.h>
using namespace std;

//观察:a[i]==1的话,这项必须增加

const int N=1e5+5;
int a[N];

void solve(){
    int n;
    cin>>n;
    int cnt=0;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {   
        cin>>a[i];
        if(a[i]==1)cnt++;
        else sum+=a[i];
    }
    if(n==1){
        cout<<"NO\n";
        return;
    }
    if(sum>=n)cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
#define p_queue priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int sum=0;
    int mn=1e9,mx=-1e9;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        mn=min(mn,a);
        mx=max(mx,a);
        sum+=a;
    }
    if(sum-mx==x){
        cout<<mn<<'\n';
    }else if(sum-mn==x){
        cout<<mx<<'\n';
    }else{
        if(x-(sum-mn-mx)>100){
            cout<<"-1\n";
        }else if(x-(sum-mn-mx)<=0){
            cout<<"0\n";
        }else{
            cout<<x-(sum-mn-mx)<<'\n';
        }
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstdlib>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second

const int N=1e5+5;
ll pref[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        pref[i]=pref[i-1]^a;
    }
    ll ans=0;
    for(int j=0;j<30;j++){
        int cnt[2]={1,0};
        ll bit=0;
        for(int i=1;i<=n;i++){
            int x=pref[i]>>j&1;
            bit+=cnt[x^1];
            cnt[x]++;
        }
        ans+=(1<<j)*bit;
    }
    cout<<ans<<endl;
    return 0;
}
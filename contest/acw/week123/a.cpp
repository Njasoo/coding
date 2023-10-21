#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        ll sum=a+b+c+n;
        if(sum%3==0){
            if(sum/3>=a&&sum/3>=b&&sum/3>=c){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cout<<"NO\n";
        }
    }   
    return 0;
}
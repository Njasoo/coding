#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define endl '\n'
#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
//lalala~~~
/*
*/
int my_compare(string s1,string s2){
    if(s1==s2)return 0;
    if(s1.size()==s2.size())
        if(s1>s2)return 1;
        else return -1;
    else
        if(s1.size()>s2.size())return 1;
        else return -1;
}
//hahaha!!!
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vt<int> a(n),b(n),c(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
        vt<vt<int>> want(n+1),need(n+1);
        for(int i=0;i<n;i++){
            want[b[i]].pb(i);
            if(a[i]!=b[i]){
                need[b[i]].pb(i);
            }
        }
        if(want[c.back()].empty()){
            cout<<"NO"<<endl;
            continue;
        }
        vt<int> ans(m);
        for(int i=m-1;i>=0;i--){
            if(!need[c[i]].empty()){
                ans[i]=need[c[i]].back();
                need[c[i]].pop_back();
            }else if(!want[c[i]].empty()){
                ans[i]=want[c[i]].back();
            }else{
                ans[i]=ans.back();
            }
        }
        int ok=1;
        for(int i=1;i<=n;i++){
            if(!need[i].empty()){
                ok=0;
                break;
            }
        }
        if(ok){
            cout<<"YES"<<endl;
            for(int i=0;i<m;i++){
                cout<<ans[i]+1<<' ';
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }      
    return 0;
}
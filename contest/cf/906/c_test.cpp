#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt0=count(s.begin(),s.end(),'0');
    int cnt1=n-cnt0;
    if(cnt0!=cnt1){
        cout<<"-1\n";
        return;
    }
    if(n&1){
        cout<<"-1\n";
        return;
    }
 
    vector<int>ans;
    
    string t="01";
    int L=0,R=n-1;
    while(L<R){
        if(s[L]!=s[R]){
            L++,R--;
            continue;
        } 
        if(s[L]=='0'){
            ans.push_back(R+1);
            s.insert(R+1,t);
            R+=2;
        } else {
            ans.push_back(L);
            s.insert(L,t);
            R+=2;
        }
    }
 
    cout<<ans.size()<<'\n';
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
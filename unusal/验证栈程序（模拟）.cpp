 #include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define endl '\n'
#define sz(x) (int)(x).size()
const int N=1e5+5;
int st[N],a[N],b[N];
void solve(){
    int n;
    cin>>n;
    int top=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int idx=1;
    for(int i=1;i<=n;i++){
        st[++top]=a[i];
        while(top>0 && st[top]==b[idx]){
            idx++;
            top--;
        }
    }
    if(top==0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }   
    return 0;
}
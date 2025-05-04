#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define ts cerr<<"hi";
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define endl '\n'

const int N=2e5+5;
ll a[N],suf[N],ans;
int n,k;

void rec(int idx,ll cur,int cntk)
{
    // db(idx),db(cur),db(cntk),el;
    if(cntk==0)
    {
        ans=max(ans,cur);
        return;
    }
    if(n-idx+1==cntk)
    {
        ans=max(ans,cur^suf[idx]);
        return;
    }
    rec(idx+1,cur^a[idx],cntk-1);
    rec(idx+1,cur,cntk);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]^a[i];
    rec(1,0,k);
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr<<#x<<"="<<(x)<< " "
#define el cerr<<endl

// 两人轮流的游戏，可以转换为一种类似带悔贪心的问题

const int N=2e5+5;
int a[N], b[N], id[N];

void solve() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) cin>>b[i];
    ll ans=0;
    for (int i=1; i<=n; i++) {
        ans-=b[i]-1;
        id[i]=i;
    }
    sort(id+1, id+1+n, [&](int i, int j) {
        return a[i]+b[i]>a[j]+b[j];
    });
    for (int i=1; i<=n; i+=2) {
        ans+=(a[id[i]]+b[id[i]]-2);
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while (tt--) solve();
    return 0;
}
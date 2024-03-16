#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr<<#x<<"="<<(x)<< " "
#define el cerr<<endl

const int N=105;
int a[N];

void solve(int test_no) {
    int n;
    cin>>n;
    for (int i=1; i<=n+n; i++) {
        cin>>a[i];
    }
    sort(a+1, a+1+n+n);
    int ans=0;
    for (int i=1; i<=n+n; i+=2) {
        ans+=a[i];
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    for (int i=1; i<=tt; i++) {
        solve(i);
    }
    return 0;
}
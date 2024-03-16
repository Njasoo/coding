#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr<<#x<<"="<<(x)<< " "
#define el cerr<<endl

void solve(int test_no) {
    int n;
    cin>>n;
    int l=1, r=n;
    for (int i=1; i<=n; i++) {
        if (i%2) cout<<l++<<" ";
        else cout<<r--<<" ";
    }
    cout<<'\n';
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
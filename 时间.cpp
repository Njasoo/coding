#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr<<#x<<"="<<(x)<< " "
#define el cerr<<endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=n%12;
    if (!ans) cout<<"12\n";
    else cout<<ans<<'\n';
    return 0;
}
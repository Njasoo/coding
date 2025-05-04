#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N=1e5+5;
int dp[N]; //dp[i]: [1, i]区间内最大的j使得[j, i]中包含两个数a^b=x
map<int,int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        dp[i]=max(dp[i-1], pos[x^a]);
        pos[a]=i;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        if(dp[r]>=l)cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
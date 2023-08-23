#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 505;
long long dp[N][N];

int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0);
    int V, G;
    cin >> V >> G;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, v, g;
        cin >> t >> v >> g;
        for (int j = V; j >= v; j--) {
            for (int k = G; k >= g; k--) {
                dp[j][k] = max(dp[j][k], dp[j - v][k - g] + t);
            }
        }
    }
    cout << dp[V][G] << '\n';
    return 0;
}
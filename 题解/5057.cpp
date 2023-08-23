#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1e5 + 5;
long long sum[N];

void solve() {
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        long long part1 = sum[i] % p;
        long long part2 = (sum[n] - sum[i]) % p;
        ans = max(ans, part1 + part2);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
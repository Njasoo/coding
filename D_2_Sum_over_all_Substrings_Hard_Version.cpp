#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> dp(n); // dp[i]：以i为左端点的所有子串的贡献之和
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            if (i + 3 >= n) dp[i] = n - i;
            else dp[i] = dp[i + 3] + n - i; // i + 3是完全没有关联的
        } else {
            if (i == n - 1) dp[i] = 0; // 只有一个零是不会有贡献的
            else dp[i] = dp[i + 1];
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
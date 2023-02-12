#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
// if b[i] == 1, dp[i] = 0;
// else dp[i] := dp[i - a]
const int N = 1e5 + 5;
int a[N];
bool b[N], dp[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[x] = 1;
    }
    int x;
    cin >> x;
    dp[0] = 1; // robot is at 0-th step initially
    for (int i = 1; i <= x; i++) {
        if (b[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (i >= a[j]) dp[i] |= dp[i - a[j]]; // be aware of RE
        }
    }
    // debug(dp[x]);
    cout << (dp[x] ? "Yes" : "No") << '\n';
    return 0;
}
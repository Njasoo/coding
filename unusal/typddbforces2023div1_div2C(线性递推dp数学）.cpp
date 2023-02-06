#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
// for ... + y[i-1] * x[i] + y[i] * x[i+1] + ...
// assume y[i-1] < x[i+1]
// if x[i] is not the maximum
// then increase x[i] by 1, and decrease y[i] by 1
// the contribution is +y[i-1] - x[i+1], so the result is better
// the case of y[i-1] > x[i+1] is similiar
// so x[i] is either hit the maximum or the minimum
// which means we need to maximize the difference between x[i] and y[i]

// this one is more understandable for me
// another explaination is that F is linear function of x[i]
// so the maximum and minimum only appears in the endpoint
// so when we try to maximize x[i], y[i] becomes smaller (becasue x[i]+y[i]==a[i])
// which turns out we need to maximize the difference of x[i] and y[i]

// (x[i]-s)*(y[i]-s)>=0 -> min(x[i], y[i])>=s or max(x[i], y[i])<=s
// x[i]>=s and y[i]=a[i]-x[i]>=s -> x[i]<=a[i]-s
// x[i]<=s and x[i]>=a[i]-s
// and x[i] and y[i] must be non-negative
// when a[i] >= s, the Endpoint is either x[i]=s or x[i]=a[i]-s
// when a[i] < s, the Endpoint of x[i] is 0 or a[i]

// dp[i][0] means we pick x[i]=s
// dp[i][1] means we pick x[i]=a[i]-s
const int N = 2e5 + 5;
long long dp[N][2], x[N][2], y[N][2], a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, s;
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i < n; i++) {
            if (a[i] < s) { // x[i], y[i] must be non-negative, I forgot
                x[i][0] = 0, y[i][0] = a[i];
                x[i][1] = a[i], y[i][1] = 0;
            } else {
                x[i][0] = s, y[i][0] = a[i] - s;
                x[i][1] = a[i] - s, y[i][1] = s;
            }
        }
        dp[2][0] = a[1] * x[2][0];
        dp[2][1] = a[1] * x[2][1];
        for (int i = 3; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0] + y[i - 1][0] * x[i][0], dp[i - 1][1] + y[i - 1][1] * x[i][0]); // don't type the wrong symbol
            dp[i][1] = min(dp[i - 1][0] + y[i - 1][0] * x[i][1], dp[i - 1][1] + y[i - 1][1] * x[i][1]);
        }
        cout << min(dp[n - 1][0] + y[n - 1][0] * a[n], dp[n - 1][1] + y[n - 1][1] * a[n]) << '\n';
    }
    return 0;
}
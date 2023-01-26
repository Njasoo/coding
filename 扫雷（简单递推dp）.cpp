#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n;
int a[N], dp[N];
// 确定一个位置就可以确定整行
int f(int s) {
    dp[1] = s;
    for (int i = 2; i <= n; i++) {
        dp[i] = a[i - 1] - dp[i - 1] - dp[i - 2];
        if (dp[i] < 0 || dp[i] > 1) return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != dp[i - 1] + dp[i] + dp[i + 1]) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }       
    cout << f(1) + f(0) << '\n';
    return 0;
}
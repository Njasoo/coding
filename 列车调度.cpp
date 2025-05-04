#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define heap priority_queue
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

// 用队列模拟超时了，换个方法，其实本质上要求的是下降子序列的个数，这等价于最长上升子序列的长度
const int N = 1e5 + 5;
int dp[N], a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1e9;
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        int p = lower_bound(dp + 1, dp + i, a[i]) - dp;
        p--;
        dp[p + 1] = min(dp[p + 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (dp[i] != 1e9) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
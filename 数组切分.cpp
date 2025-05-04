#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long ll;

// dp[i]: 前i个数的划分总数
const int N = 1e4 + 5;
const ll MOD = 1e9 + 7;
ll a[N], dp[N], st1[N][21], st2[N][21];
int n, lg[N];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) {
        st1[i][0] = a[i];
        st2[i][0] = a[i];
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
            st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query1(int l, int r) {
    int k = lg[r - l + 1];
    return max(st1[l][k], st1[r - (1 << k) + 1][k]);
}

ll query2(int l, int r) {
    int k = lg[r - l + 1];
    return min(st2[l][k], st2[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (query1(j, i) - query2(j, i) == i - j) {
                dp[i] += dp[j - 1];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
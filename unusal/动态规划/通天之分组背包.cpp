#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define vt vector
#define sz(x) (int) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second

const int N = 1005;
int dp[N][N];
int d[N], f[N], w[N], v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num = 0;
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> w[i] >> v[i] >> x;
        num = max(x, num);
        d[x]++; // 表示第x种类的物品有多少种
        dp[x][d[x]] = i;
    }
    for (int k = 1; k <= num; k++) {
        for (int j = m; j >= 0; j--) { // 倒着来, 这样一开始即使背包比较空旷也不会有超过一件的同组物品占据了背包
            for (int i = 1; i <= d[k]; i++) {
                int px = dp[k][i];
                if (j >= w[px]) {
                    f[j] = max(f[j - w[px]] + v[px], f[j]);
                }
            }
        }
    }
    cout << f[m] << '\n';
    return 0;
}
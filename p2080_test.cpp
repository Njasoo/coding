#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// O(2 ^ n * n), 加上剪枝

const int N = 35;
int a[N], b[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 1e9;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cura = 0, curb = 0;
        for (int i = 0; i < n; i++) { // 这一步相比起递归时间复杂度更高
            if (mask >> i & 1) {
                cura += a[i + 1];
                curb += b[i + 1];
            }
        }
        if (cura + curb >= v) ans = min(ans, abs(cura - curb));
        if (ans == 0) break; // 剪枝, 过了
    }
    if (ans == 1e9) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}
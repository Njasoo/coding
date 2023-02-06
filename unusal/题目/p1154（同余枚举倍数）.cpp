#include <bits/stdc++.h>
using namespace std;
// a mod k == b mod k -> a - b mod k == 0
// 也就是说要找一个k使得所有的a - b mod k != 0
// 也就是说a - b不是k的倍数
// 可以反过来枚举k的倍数，然后判断是否在数列中
const int N = 5e3 + 5;
const int N2 = 1e6 + 5;
const int MN = 1e6;
bool vis[N2];
int n;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vis[abs(a[i] - a[j])] = 1; // 枚举k的倍数的时候是正数，所以abs
        }
    }
    bool flag;
    int ans = 0;
    for (int k = 1; k <= MN; k++) {
        flag = 1;
        for (int j = k; j <= MN; j += k) {
            if (vis[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = k;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
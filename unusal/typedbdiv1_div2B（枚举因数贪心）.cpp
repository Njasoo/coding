#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
// 100 = 2 ^ 2 * 5 ^ 2 -> 2 * 5 + 2 * 5
// 贪心，每次把剩下的质因数每种各取一个，最多可以组成max(p_i)个积
// 不会码，抄题解
// 质因数分解如果没有筛素数出来的话，时间复杂度应该是(sqrt(N))
const int N = 55;
pair<int, int> product[N]; // (次方, 数字)
int part[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int idx = 0;
        for (int i = 2; i * i <= n; i++) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            if (cnt > 0) product[++idx] = {cnt, i};
        }
        if (n != 1) { // 剩下一个素因子
            product[++idx] = {1, n};
        }
        sort(product + 1, product + 1 + idx); // 按照次方大到小排序，因为次方大的永远和次方小的组成积
        part[idx + 1] = 1; // little trick 1
        for (int i = idx; i >= 1; i--) {
            part[i] = part[i + 1] * product[i].second;
        }
        long long ans = 0;
        for (int i = 1; i <= idx; i++) {
            ans += (product[i].first - product[i - 1].first) * part[i]; // 只能用前面部分用完剩下的次方 little trick 2
        }
        cout << ans << '\n';
    }   
    return 0;
}
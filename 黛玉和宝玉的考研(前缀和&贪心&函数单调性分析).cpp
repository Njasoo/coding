#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define ll long long

// 假设喜欢某一行, 那么不喜欢的每一列都对答案有贡献
// 假设某k行喜欢其中的a行, 某k列喜欢其中的b列
// 那么对答案的贡献就是a * (k - b) + (k - a) * b
// ka + kb - 2ab = b * (k - 2a) + ka
// 看成关于b的一个线性函数, a作为一个常数, k-2a > 0时, b越大越好, 反之b越小越好
// 不过直接代入两个b的最值比较一下就好
const int N = 2e5 + 5;
char s[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> (s + 1) >> (t + 1);
    int mn_col_1 = m, mx_col_1 = 0;
    int cur_col_1 = 0;
    for (int i = 1; i <= k; i++) {
        cur_col_1 += (t[i] == '1');
    }
    mx_col_1 = max(mx_col_1, cur_col_1);
    mn_col_1 = min(mn_col_1, cur_col_1);
    for (int i = 2; i + k - 1 <= m; i++) {
        if (t[i - 1] == '1') {
            cur_col_1--;
        }
        if (t[i + k - 1] == '1') {
            cur_col_1++;
        }
        mx_col_1 = max(mx_col_1, cur_col_1);
        mn_col_1 = min(mn_col_1, cur_col_1);
    }
    int cur_row_1 = 0;
    for (int i = 1; i <= k; i++) {
        cur_row_1 += (s[i] == '1');
    }
    ll ans = 1LL * cur_row_1 * (k - mn_col_1) + 1LL * (k - cur_row_1) * mn_col_1;
    ans = max(ans, 1LL * cur_row_1 * (k - mx_col_1) + 1LL * (k - cur_row_1) * mx_col_1);
    for (int i = 2; i + k - 1 <= n; i++) {
        if (s[i - 1] == '1') {
            cur_row_1--;
        }
        if (s[i + k - 1] == '1') {
            cur_row_1++;
        }
        ans = max(ans, 1LL * cur_row_1 * (k - mn_col_1) + 1LL * (k - cur_row_1) * mn_col_1);
        ans = max(ans, 1LL * cur_row_1 * (k - mx_col_1) + 1LL * (k - cur_row_1) * mx_col_1);
    }
    cout << ans << '\n';
    return 0;
}
#pragma GCC optimize(3,"Ofast") // 好吧不能吸
#include <bits/stdc++.h>
using namespace std;
// 相比起尺取法，二分更加灵活
// 二分枚举区间长度，检查是否合法
// 等一下，刚才看错题意了，我发现尺取法好像也能做
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
string ss[N];
map<string, int> cnt;
map<string, bool> want;
int ans1, ans2;
inline bool check(int mid) {
    cnt.clear();
    int tot = 0;
    for (int i = 1; i <= mid; i++) {
        if (want[ss[i]] == 1) {
            cnt[ss[i]]++;
            if (cnt[ss[i]] == 1) tot++;
        }
    }
    if (tot == ans1) return 1;
    for (int i = 2; i + mid - 1 <= m; i++) {
        if (want[ss[i - 1]] == 1) {
            cnt[ss[i - 1]]--;
            if (cnt[ss[i - 1]] == 0) tot--;
        }
        if (want[ss[i + mid - 1]] == 1) {
            cnt[ss[i + mid - 1]]++;
            if (cnt[ss[i + mid - 1]] == 1) tot++;
        }
        if (tot == ans1) return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        want[s] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ss[i];
        cnt[ss[i]]++;
        if (cnt[ss[i]] == 1 && want[ss[i]] == 1) ans1++;
    }
    int l = 0, r = m;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
// 好，原来是尺取法模板题，又搞了我半天
int n, m;
string ss[N];
map<string, bool> want;
map<string, int> cnt;
int ans1, ans2 = INF;
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
        if (want[ss[i]] == 1 && ++cnt[ss[i]] == 1) ans1++;
    }
    cnt.clear();
    cout << ans1 << '\n';
    int tot = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= m && tot < ans1) {
            if (want[ss[j]] == 1) {
                if (++cnt[ss[j]] == 1) tot++;
            }
            j++;
        }
        if (tot == ans1) ans2 = min(ans2, j - i);
        else break;
        if (want[ss[i]] == 1) {
            cnt[ss[i]]--;
            if (cnt[ss[i]] == 0) tot--;
        }
    }
    if (ans1 == 0) {
        cout << 0 << '\n';
    } else {
        cout << ans2 << '\n';
    }
    return 0;
}
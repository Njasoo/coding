#include <bits/stdc++.h>

using namespace std;

int maxtime, nowtime, maxdeep, sum = 0, ans = 0;
int s[4], a[25];

void dfs(int x) {
    if (x > maxdeep) {
        maxtime = max(maxtime, nowtime);
        return;
    }
    if (nowtime + a[x] <= sum / 2) { // 尽量把题目分成时间相等的两份
        nowtime += a[x];
        dfs(x + 1);
        nowtime -= a[x];
    }
    dfs(x + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        sum = 0; // 初始化
        maxdeep = s[i];
        nowtime = 0;
        maxtime = 0;
        for (int j = 1; j <= s[i]; j++) {
            cin >> a[j];
            sum += a[j];
        }
        dfs(1);
        ans += (sum - maxtime);
    }
    cout << ans << '\n';
    return 0;
}
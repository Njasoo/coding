#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int MN = 1000;
int a[MN + 5], b[MN + 5];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = n;
    vector<pair<int, int>> ans_op;
    for (int i = 1; i <= n; i++) {
        memcpy(b, a, sizeof(a));
        vector<pair<int, int>> op;
        bool flag = 1;
        int cnt = 0;
        for (int j = i - 1; j >= 1; j--) {
            b[j] = b[j + 1] - k;
            int dis = b[j] - a[j];
            if (b[j] <= 0) {
                flag = 0;
                break;
            }
            if (b[j] != a[j]) {
                cnt++;
                op.push_back({j, dis});
            }
        }
        for (int j = i + 1; j <= n; j++) {
            b[j] = b[j - 1] + k;
            int dis = b[j] - a[j];
            if (b[j] != a[j]) {
                cnt++;
                op.push_back({j, dis});
            }
        }
        if (flag) {
            if (cnt < ans) {
                ans = cnt;
                ans_op = op;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < (int) ans_op.size(); i++) {
        if (ans_op[i].second > 0) {
            cout << "+ " << ans_op[i].first << " " << ans_op[i].second << '\n';
        } else {
            cout << "- " << ans_op[i].first << " " << -ans_op[i].second << '\n';
        }
    }
    return 0;
}
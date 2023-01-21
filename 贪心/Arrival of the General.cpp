#include <bits/stdc++.h>

using namespace std;

/*
最大的尽量选择位置靠左的, 最小的尽量选择位置靠右的
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int inf = (int) 1e9;
    int mn = inf, mx = 0;
    int mn_pos = 0, mx_pos = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > mx) {
            mx = a;
            mx_pos = i;
        }
        if (a <= mn) {
            mn = a;
            mn_pos = i;
        }
    }
    int ans = mx_pos + (n - 1 - mn_pos);
    if (mx_pos > mn_pos) {
        ans--;
    }
    cout << ans << '\n';
    return 0;
}
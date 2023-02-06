#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    const int inf = 1e9;
    long long cnt = 0, ans = -inf;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        cnt += a;
        ans = max(ans, cnt);
        if (cnt < 0) {
            cnt = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
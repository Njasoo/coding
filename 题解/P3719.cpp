#include <bits/stdc++.h>
using namespace std;
int solve() {
    int res = 0;
    char ch;
    while (cin >> ch) {
        if (ch == '(') res += solve();
        if (ch == '|') return max(res, solve());
        if (ch == 'a') res++;
        if (ch == ')') break;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int ans = 0;
//    for (int i = 1; i <= 100; i++) {
//        ans += solve();
//    }
//    cout << ans << '\n';
	cout << solve() << '\n';
    return 0;
}

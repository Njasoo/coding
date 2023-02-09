#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            ans += a;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 15;
int c[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int lenc;
        cin >> lenc;
        for (int j = 1; j <= lenc; j++) {
            int a;
            cin >> a;
            c[i] |= (1 << a);
        }
    }
    int ans = 0;
    for (int mask = 2; mask < (1 << (m + 1)); mask += 2) {
        int cnt = 1;
        for (int i = 1; i <= m; i++) {
            if (mask >> i & 1) {
                cnt |= c[i];
            }
        }
        if (cnt == (1 << (n + 1)) - 1) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
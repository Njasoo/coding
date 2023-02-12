#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        b = min(b, a);
        long long cnt1 = b * n;
        long long cnt2 = n / (m + 1) * m * a + (n - (n / (m + 1)) * (m + 1)) * b;
        cout << min(cnt1, cnt2) << '\n';
    }
    return 0;
}
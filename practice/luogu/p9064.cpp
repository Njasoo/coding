#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 5;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 1e9;
    for (int i = 1; i + m - 1 <= n; i++) {
        ans = min(ans, a[i + m - 1] - a[i]);
    }
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], ans[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }       
    sort(a + 1, a + 1 + n);
    int cnt = 0;
    for (int i = 1, j = n; i < j; i++, j--) {
        ans[++cnt] = a[j];
        ans[++cnt] = a[i];
    }
    if (n % 2) {
        ans[++cnt] = a[(n + 1) / 2];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
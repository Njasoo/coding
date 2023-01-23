#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = res * u;
        v >>= 1;
        u *= u;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;       
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                int len = (int) log10(a[j]) + 1;
                int ta_i = a[i];
                ta_i *= power(10, len);
                ta_i += a[j];
                if (ta_i <= k) ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
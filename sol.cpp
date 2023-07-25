#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (tt--) {
        solve();
    }
    return 0;
}
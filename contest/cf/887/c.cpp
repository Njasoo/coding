#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        int cnt = 0;
        while (a[i]) {
            a[i] /= k;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long n;
long long p[400005];

void solve() {
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
        ans += llabs(p[i]);
    }
    if (n % 2 == 0) {
        sort(p + 1, p + 1 + n + n);
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += llabs(p[i] + 1);
        }
        for (int i = n + 1; i <= n + n; i++) {
            cnt += llabs(p[i] - 1);
        }
        ans = min(ans, cnt);
    }
    if (n == 1) {
        cout << min(llabs(p[2] - p[1]), llabs(p[1] - p[2])) << '\n';
        return;
    }
    if (n == 2) {
        long long cnt = 0;
        for (int i = 1; i <= n * 2; i++) {
            cnt += llabs(p[i] - 2);
        }
        ans = min(ans, cnt);
        cout << ans << '\n';
        return;
    }
    if (n % 2 == 0) {
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += llabs(p[i] + 1);
        }
        for (int i = n + 1; i <= n + n; i++) {
            cnt += llabs(p[i] - 1);
        }
        ans = min(ans, cnt);
        cout << ans << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }	
	return 0;
}


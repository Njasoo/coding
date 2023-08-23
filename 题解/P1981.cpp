#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    cin >> a[++cnt];
    char ch;
    while (cin >> ch >> a[++cnt]) {
        a[cnt] %= 10000;
        if (ch == '*') {
            a[cnt] *= a[cnt - 1];
            a[cnt - 1] = 0;
            a[cnt] %= 10000;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
    	cerr << a[i] << " \n"[i == cnt];
	}
    for (int i = 1; i <= cnt; i++) {
        ans = (ans + a[i]) % 10000;
    }
    cout << ans << '\n';
    return 0;
}

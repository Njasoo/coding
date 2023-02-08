#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i;
        if (ans > 2000) break;
    }   
    cout << ans << '\n';
    return 0;
}
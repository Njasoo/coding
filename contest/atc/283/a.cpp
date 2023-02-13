#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;   
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        ans *= a;
    }
    cout << ans << '\n';
    return 0;
}
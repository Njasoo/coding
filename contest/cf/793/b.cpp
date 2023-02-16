#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int ans = (1 << 31) - 1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x != i) {
                ans &= x;
            }
        }
        cout << ans << '\n';
    }   
    return 0;
}
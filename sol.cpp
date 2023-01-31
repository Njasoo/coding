#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, n;
        cin >> m >> n;
        for (int i = m; i <= n; i++) {
            if (i == 1) continue;
            bool isprime = 1;
            int tempi = i;
            for (int j = 2; j * j <= tempi; j++) {
                if (tempi % j == 0) {
                    isprime = 0;
                    break;
                }
            }
            if (isprime) cout << i << '\n';
        }
        cout << '\n';
    }
    return 0;
}
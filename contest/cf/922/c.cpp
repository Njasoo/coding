#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, r;
        cin >> a >> b >> r;
        if (a < b) swap(a, b);
        int lena = 64 - __builtin_clzll(a);
        long long x = 0;
        bool start = false;
        for (int i = lena - 1; i >= 0; i--) {
            bool bita = a >> i & 1;
            bool bitb = b >> i & 1;
            if (bita && !bitb && start) {
                if ((x ^ (1LL << i)) <= r) {
                    x ^= (1LL << i);
                }
            }
            if (bita != bitb) {
                start = true;
            }
        }
        cout << ((a ^ x) - (b ^ x)) << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    for (int mask = 1; mask < (1 << (n + 1)); mask += 2) {
        if (__builtin_popcount(mask) != r + 1) continue;
        for (int i = 1; i <= n; i++) {
            if ((mask >> i) & 1) {
                cout << setw(3) << i;
            }
        }
        cout << '\n';
    }   
    return 0;
}
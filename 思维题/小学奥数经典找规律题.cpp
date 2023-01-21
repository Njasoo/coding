#include <bits/stdc++.h>

using namespace std;

long long f[6];
const long long MOD = (int) 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x, y;
    cin >> x >> y;    
    f[0] = x - y;
    f[1] = x;
    f[2] = y;
    f[3] = y - x;
    f[4] = -x;
    f[5] = -y;
    int n;
    cin >> n;
    while (f[n % 6] < 0) {
        f[n % 6] += MOD;
    }
    cout << f[n % 6] % MOD << '\n';
    return 0;
}
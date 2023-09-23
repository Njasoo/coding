#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        long double x, y, z;
        cin >> x >> y >> z;
        cout << (long long) (floor((z - y) / x) * x + y) << '\n';
    }      
    return 0;
}
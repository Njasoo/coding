#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
const int N = 1e2 + 5;
const int M = 998244353;

inline void solve() {
    ll a, b;
    cin >> a >> b;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (i * i + j * j == b * b) {
                for (int x = 1; x <= 1000; x++) {
                    for (int y = 1; y <= 1000; y++) {
                        if (x * i == y * j && x * x + y * y == a * a&&j!=y) {
                            cout << "YES\n";
                            cout << 0 << ' ' << 0 << endl;
                            cout << i << ' ' << j << endl;
                            cout << -x << ' ' << y << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)solve();
}

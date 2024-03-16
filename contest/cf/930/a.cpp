#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    int i;
    for (i = 1; i * 2 <= n; i *= 2) {}
    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}
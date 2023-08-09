#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

void solve() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n == 2) {
        cout << "2\n";
        return;
    }
    for (long long i = 2; i <= n; i++) {
        if (n % i) {
            cout << i - 1 << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
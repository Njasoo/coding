#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

void solve() {
    int n;
    cin >> n;
    while (n % 2 == 0) {
        n /= 2;
    }
    cout << (n == 1 ? "YES" : "NO") << '\n';
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
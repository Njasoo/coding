#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    int cnt[3] {};
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        cnt[a % 3]++;
    }
    if (sum % 3 == 0) {
        cout << "0\n";
    } else if (sum % 3 == 2) {
        cout << "1\n";
    } else {
        if (cnt[1]) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
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
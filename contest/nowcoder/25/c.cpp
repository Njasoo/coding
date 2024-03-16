#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    i64 ans = 0;
    for (int i = n - 3; i >= 0; i--) {
        int d = min({a[i], a[i + 1] / 2, a[i + 2] / 3});
        ans += d * 5;
        a[i] -= d, a[i + 1] -= d * 2, a[i + 2] -= d * 3;
    }
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << '\n';
    return 0;
}
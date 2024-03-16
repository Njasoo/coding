#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i + 1;
    }
    sort(a.rbegin(), a.rend());
    cout << a[0] << " ";
    for (int i = 1; i < n; i++) {
        a[i] = min(a[i], a[i - 1] - 1);
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
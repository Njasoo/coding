#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N], b[N];
void solve() {
    int n;
    cin >> n;
    vector<int> odd_pos, even_pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odd_pos.push_back(i);
        } else {
            even_pos.push_back(i);
        }
    }
    sort(a + 1, a + 1 + n);
    int odd_p = 0, even_p = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            b[odd_pos[odd_p++]] = a[i];
        } else {
            b[even_pos[even_p++]] = a[i];
        }
    }
    if (is_sorted(b + 1, b + 1 + n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
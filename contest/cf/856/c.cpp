#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= i - mid + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << i - r + 1 << " ";
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
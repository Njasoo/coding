#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        bool visl = 0, visr = 0;
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            if (l == k) visl = 1;
            if (r == k) visr = 1;
        }
        cout << (visl && visr ? "YES" : "NO") << '\n';
    }   
    return 0;
}
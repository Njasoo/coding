#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 5;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int mn = 1, mx = n;
        pair<int, int> ans;
        for (int i = 1, j = n; i <= n; i++) {
            while (j >= i && (a[j] == mn || a[j] == mx)) {
                if (a[j] == mn) mn++;
                if (a[j] == mx) mx--;
                j--;
            }
            if (j < i) break;
            if (a[i] != mn && a[i] != mx) {
                ans = {i, j};
                break;
            }
            if (a[i] == mn) {
                mn++;
            }
            if (a[i] == mx) {
                mx--;
            }
        }
        if (ans.first && ans.second) {
            cout << ans.first << " " << ans.second << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
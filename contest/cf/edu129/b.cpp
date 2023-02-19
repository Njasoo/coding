#include <bits/stdc++.h>
using namespace std;
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
        int m;
        cin >> m;
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            sum += x;
            sum %= n;
        }
        cout << a[sum + 1] << '\n';
    }
    return 0;
}
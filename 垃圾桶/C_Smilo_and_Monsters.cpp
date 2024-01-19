#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
long long a[N], sum[N];

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
        sort(a + 1, a + 1 + n, greater<int>());
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        int need = 0;
        while (sum[need] < sum[n] / 2) {
            need++;
        }
        cout << (sum[n] + 1) / 2 + need << '\n';
    }
    return 0;
}
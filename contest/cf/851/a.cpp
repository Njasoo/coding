#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 5;
int sum[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + (a == 2);
        }
        bool flag = 0;
        int ans = 0;
        for (int k = 1; k < n; k++) {
            int l = sum[k], r = sum[n] - sum[k];
            if (l == r) {
                ans = k;
                flag = 1;
                break;
            }
        }
        cout << (flag ? ans : -1) << '\n';
    }   
    return 0;
}
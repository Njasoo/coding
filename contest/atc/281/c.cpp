#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

const int N = 1e5 + 5;
long long a[N], sum[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    t -= t / sum[n] * sum[n];
    // db(sum[n]);
    // db(t);
    int l = 0, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (sum[mid] <= t) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans + 1 << " " << t - sum[ans] << '\n';
    return 0;
}
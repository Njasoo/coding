#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e5 + 5;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    while (q--) {
        ll c;
        cin >> c;
        double l = 0, r = 1e18;
        int iter = 1000;
        while (iter--) {
            double mid = (l + r) / 2;
            int i = 1;
            ll rank = 0;
            for (int j = 1; j <= n; j++) {
                while (i <= n && a[i] <= b[j] * mid) {
                    i++;
                }
                rank += i - 1;
            }
            if (rank >= c) {
                r = mid;
            } else {
                l = mid;
            }
        }
        double mn_dis = 1e18;
        pair<ll, ll> ans;
        for (int i = 1; i <= n; i++) {
            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (1.0 * a[i] / b[mid] > r) {
                    double cnt_dis = 1.0 * a[i] / b[mid] - r;
                    if (cnt_dis < mn_dis) {
                        ans = {i, mid};
                        mn_dis = cnt_dis;
                    }
                    lo = mid + 1;
                } else {
                    double cnt_dis = r - 1.0 * a[i] / b[mid];
                    if (cnt_dis < mn_dis) {
                        mn_dis = cnt_dis;
                        ans = {i, mid};
                    }
                    hi = mid - 1;
                }
            }
        }
        ll g = __gcd(a[ans.first], b[ans.second]);
        cout << a[ans.first] / g << " " << b[ans.second] / g << '\n';
    }
    return 0;
}
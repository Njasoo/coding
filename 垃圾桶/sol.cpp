#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define db(x) cerr << (#x) << "=" << x << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    long long now_sit = 0;
    for (int i = 0; i < q; i++) {
        long long k;
        cin >> k;
        if (now_sit + k >= sum[n]) {
            cout << n << '\n';
            now_sit = 0;
            continue;
        }
        int l = 1, r = n;
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (now_sit + k < sum[mid]) {
                r = mid - 1;
                pos = mid;
            } else {
                l = mid + 1;
            }
        }
        now_sit += k;
        cout << n - pos + 1 << '\n';
    }
    return 0;
}
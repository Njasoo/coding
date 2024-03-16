#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = 0;
    int64_t cur = 0, ans = 0;
    while (i < n) {
        j = max(j, i);
        while (j < n && cur < k) {
            cur += a[j];
            j++;
        }
        if (cur >= k) ans += n - j + 1;
        else break;
        cur -= a[i];
        i++;
    }
    cout << ans << '\n';
    return 0;
}
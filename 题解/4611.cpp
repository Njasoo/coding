#include <bits/stdc++.h>

using namespace std;

long long power(long long a, int b, int k) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % k;
        a = a * a % k;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<pair<int, int>, bool> hs;
    map<pair<int, int>, int> cnt;
    int maxlen = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int mod = a[i] % k;
        int len = (int) log10(a[i]) + 1;
        maxlen = max(maxlen, len);
        if (mod == 0) mod = k;
        cnt[{len, mod}]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp_ai = a[i] % k;
        for (int j = 1; j <= maxlen; j++) {
            int temp_10 = power(10, j, k);
            int mod = 1LL * temp_ai * temp_10 % k;
            if (cnt[{j, k - mod}]) {
                if (k - mod == mod || mod == 0) {
                    ans += cnt[{j, k - mod}] - 1; // not count itself
                    continue;
                }
                ans += cnt[{j, k - mod}];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
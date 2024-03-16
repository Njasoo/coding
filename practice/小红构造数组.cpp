#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t x;
    cin >> x;
    if (x == 1) {
        cout << "-1\n";
        return 0;
    }
    map<int64_t, int> cnt;
    vector<int64_t> primes;
    for (int64_t i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            cnt[i]++;
            primes.push_back(i);
        }
    }
    if (x > 1) primes.push_back(x);
    vector<int64_t> ans(primes.size());
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    sort(primes.begin(), primes.end(), [&](int64_t i, int64_t j) {
        return cnt[i] > cnt[j];
    });
    int p = 0;
    for (int i = 0; i < ans.size(); i += 2) {
        ans[i] = primes[p];
        cnt[primes[p]]--;
        if (cnt[primes[p]] == 0) p++;
    }
    for (int i = 1; i < ans.size(); i += 2) {
        ans[i] = primes[p];
        cnt[primes[p]]--;
        if (cnt[primes[p]] == 0) p++;
    }
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] == ans[i - 1]) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
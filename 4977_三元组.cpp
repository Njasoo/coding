#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }      
    unordered_map<long long, long long> cnt1, cnt2;
    cnt1[a[1]]++;
    for (int i = 3; i <= n; i++) {
        cnt2[a[i]]++;
    }
    long long ans = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] % k == 0) ans += cnt1[a[i] / k] * cnt2[a[i] * k];
        cnt1[a[i]]++;
        if (cnt2[a[i + 1]]) cnt2[a[i + 1]]--;
    }
    cout << ans << '\n';
    return 0;
}
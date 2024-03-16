#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt1 = 1, cnt2 = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        cnt1 = 1LL * cnt1 * a[i] % MOD;
        cnt2 = 1LL * cnt2 * b[i] % MOD;
    }
    cout << (cnt1 + cnt2) % MOD << '\n';
    return 0;
}
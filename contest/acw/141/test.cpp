#include <bits/stdc++.h>

using namespace std;

template<class T>
struct FenWick {
    int _n;
    vector<T> tr;

    FenWick(int n) : _n(n), tr(n + 5, 0) {}
    void update(int idx, T value) {
        while (idx <= _n) {
            tr[idx] += value;
            idx += idx & -idx;
        }
    }
    T sum(int idx) {
        T res = 0;
        while (idx) {
            res += tr[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    T query(int l, int r) {
        assert(l >= 1 && r <= _n && l <= r);
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++ ) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
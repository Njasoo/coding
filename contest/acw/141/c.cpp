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
    int a[n + 5], id[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + 1 + n, [&](int i, int j) {
        return a[i] > a[j];
    });
    sort(a + 1, a + 1 + n, [&](int i, int j) {
        return i > j;
    });
    FenWick<int> tr(n);
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += tr.sum(id[i] - 1);
        tr.update(id[i], 1);
    }
    if ((cnt - n) % 2 == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
    return 0;
}
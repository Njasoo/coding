#include <bits/stdc++.h>

using namespace std;

template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable {
    int n;
    vector<vector<T>> f;
    F func;
 
    SparseTable(const vector<T>& a, const F& _func) : func(_func) {
        n = a.size();
        int max_log = 32 - __builtin_clz(n);
        f.resize(max_log);
        f[0] = a;
        for (int j = 1; j < max_log; j++) {
            f[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) <= n; i++) {
                f[j][i] = func(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 31 - __builtin_clz(to - from + 1);
        return func(f[lg][from], f[lg][to - (1 << lg) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        SparseTable<int> mxtr(a, [&](int i, int j) { return max(i, j); });
        SparseTable<int> mntr(a, [&](int i, int j) { return min(i, j); });
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if (mntr.query(l, r) == mxtr.query(l, r)) {
                cout << "-1 -1\n";
                continue;
            }
            int lo = l, hi = r;
            int pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (lo == hi) {
                    pos = mid;
                    break;
                }
                if (mntr.query(lo, mid) == mntr.query(l, r)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << pos + 1 << " ";
            lo = l, hi = r;
            pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (lo == hi) {
                    pos = mid;
                    break;
                }
                if (mxtr.query(lo, mid) == mxtr.query(l, r)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            cout << pos + 1 << '\n';
        }
        cout << '\n';
    }
    return 0;
}
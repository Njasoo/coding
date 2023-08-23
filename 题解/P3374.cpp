#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Fenwick {
    int _n;
    vector<T> t;

    Fenwick(int n) : _n(n), t(n + 1, 0) {}

    void add(int x, T k) {
        while (x <= _n) {
            t[x] += k;
            x += x & -x;
        }
    }

    T sum(int x) {
        T res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    T rangeSum(int l, int r) {
        assert(l - 1 >= 0);
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Fenwick<int> fen(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fen.add(i + 1, a);
    }

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            fen.add(x, y);
        } else {
            cout << fen.rangeSum(x, y) << '\n';
        }
    }

    return 0;
}
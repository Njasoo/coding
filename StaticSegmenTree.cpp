template<class T, class F = function<T(const T&, const T&)>>
struct StaticSegmentTree {
    vector<T> t;
    int n;
    F func;

    StaticSegmentTree(const vector<T>& a, const F& f) : n(a.size()), func(f) {
        t.resize(4 * n + 1);
        auto build = [&](auto self, int id, int l, int r) -> void {
            if (l == r) {
                t[id] = a[l - 1];
                return;
            }
            int mid = (l + r) / 2;
            self(self, id * 2, l, mid);
            self(self, id * 2 + 1, mid + 1, r);
            t[id] = func(t[id * 2], t[id * 2 + 1]);
        };
        build(build, 1, 1, n);
    }

    T query(int s, int e) {
        assert(s >= 1 && e <= n);
        auto work = [&](auto self, int id, int l, int r, int s, int e) -> T {
            if (l == s && r == e) {
                return t[id];
            }
            int mid = (l + r) / 2;
            if (e <= mid) {
                return self(self, id * 2, l, mid, s, e);
            } else if (s > mid) {
                return self(self, id * 2 + 1, mid + 1, r, s, e);
            }
            auto L = self(self, id * 2, l, mid, s, mid);
            auto R = self(self, id * 2 + 1, mid + 1, r, mid + 1, e);
            return func(L, R);
        };
        return work(work, 1, 1, n, s, e);
    }
};
template<class T>
struct SegmentTree {
    int n;
    vector<T> val, tag;

    SegmentTree(const vector<T>& a) : n(a.size()) {
        val.resize(4 * n + 1);
        tag.resize(4 * n + 1);
        auto build = [&](auto self, int id, int l, int r) -> void {
            if (l == r) {
                val[id] = a[l - 1];
                return;
            }
            int mid = (l + r) / 2;
            self(self, id * 2, l, mid);
            self(self, id * 2 + 1, mid + 1, r);
            pull(id, l, r);            
        };
        build(build, 1, 1, n);
    }

    void push(int id) {
        tag[id * 2] += tag[id];
        tag[id * 2 + 1] += tag[id];
        tag[id] = 0;
    }

    void pull(int id, int l, int r) {
        int mid = (l + r) / 2;
        val[id] = val[id * 2] + val[id * 2 + 1] + (mid - l + 1) * tag[id * 2] + (r - mid) * tag[id * 2 + 1];
    }

    void modify(int s, int e, T k) {
        s++, e++;
        update(1, 1, n, s, e, k);
    }

    void update(int id, int l, int r, int s, int e, const T& k) {
        if (s > r || e < l) {
            return;
        }
        if (s <= l && r <= e) {
            tag[id] += k;
            return;
        }
        push(id);
        int mid = (l + r) / 2;
        update(id * 2, l, mid, s, e, k);
        update(id * 2 + 1, mid + 1, r, s, e, k);
        pull(id, l, r);
    }

    T query(int l, int r) {
        l++, r++;
        return query(1, 1, n, l, r);
    }
    
    T query(int id, int l, int r, int s, int e) {
        if (e < l || s > r) {
            return 0;
        }
        if (s <= l && r <= e) {
            return val[id] + tag[id] * (r - l + 1);
        }
        push(id);
        int mid = (l + r) / 2;
        T res = query(id * 2, l, mid, s, e) + query(id * 2 + 1, mid + 1, r, s, e);
        pull(id, l, r);
        return res;
    }
};
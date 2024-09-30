namespace hjt {
    int id = 0;
    int tr[N * 32], son[N * 32][2], cnt[N], root[N];

    void update(int p, int rt, int l, int r, int x) {
        if (l == r) {
            tr[p] = cnt[x];
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            son[p][1] = son[rt][1];
            if (!son[p][0]) {
                son[p][0] = ++id;
            }
            update(son[p][0], son[rt][0], l, mid, x);
        } else {
            son[p][0] = son[rt][0];
            if (!son[p][1]) {
                son[p][1] = ++id;
            }
            update(son[p][1], son[rt][1], mid + 1, r, x);
        }
        tr[p] = tr[son[p][0]] + tr[son[p][1]];
    }

    int query1(int p, int l, int r, int s, int e) {
        if (!p) {
            return 0;
        }
        if (s > e) {
            return 0;
        }
        if (l == s && r == e) {
            return tr[p];
        }
        int mid = (l + r) / 2;
        if (e <= mid) {
            return query1(son[p][0], l, mid, s, e);
        } else if (s > mid) {
            return query1(son[p][1], mid + 1, r, s, e);
        }
        int res = query1(son[p][0], l, mid, s, mid);
        res += query1(son[p][1], mid + 1, r, mid + 1, e);
        return res;
    }

    void build() {
        cnt[b[1]]++;
        root[1] = ++id;
        for (int i = 1; i <= n; i++) {
            update(root[1], root[1], 1, n, b[i]);
        }
        for (int i = 2; i <= n; i++) {
            cnt[b[i]]++;
            root[i] = ++id;
            update(root[i], root[i - 1], 1, n, b[i]);
        }
    }

    bool check(int l, int r, int d, int k) {
        int res = query1(root[r], 1, n, 1, d) - query1(root[l - 1], 1, n, 1, d);
        return res >= k;
    }

    // 如果值比较大, 返回类型改成ll
    int query2(int range_l, int range_r, int k, int p1, int p2) {
        if (range_l == range_r) {
            return a[range_l];
        }
        // 左半值域的数的总个数
        int lft = tr[son[p2][0]] - tr[son[p1][0]];
        int mid = (range_l + range_r) / 2;
        if (k <= lft) {
            return query2(range_l, mid, k, son[p1][0], son[p2][0]);
        }
        return query2(mid + 1, range_r, k - lft, son[p1][1], son[p2][1]);
    }

    // 如果值比较大, 返回类型改成ll
    int query(int l, int r, int k) {
        return query2(1, n, k, root[l - 1], root[r]);
    }
}
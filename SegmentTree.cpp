template<class Info>
class SegmentTree {
private:
    int n;
    vector<Info> info, a;
public:
    SegmentTree(int n) {
        this->n = n;
        info.resize(4 * n + 1);
        this->a = a;
    }
    void build(int id, int l, int r) {
        if (l == r) {
            info[id] = Info();
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        info[id] = info[id * 2] + info[id * 2 + 1];
    }
    void modify(int id, int l, int r, int p, const Info& v) {
        if (l == r) {
            info[id] = v;
            return;
        }
        int mid = (l + r) / 2;
        if (p <= mid)
            modify(id * 2, l, mid, p, v);
        else
            modify(id * 2 + 1, mid + 1, r, p, v);
        info[id] = info[id * 2] + info[id * 2 + 1];
    }
    void modify(int p, const Info& v) {
        p++;
        modify(1, 1, n, p, v);
    }
    Info query(int id, int l, int r, int s, int e) {
        if (s <= l && e >= r) {
            return info[id];
        }
        if (r < s || l > e) {
            return Info();
        }
        int mid = (l + r) / 2;
        return query(id * 2, l, mid, s, e) + query(id * 2 + 1, mid + 1, r, s, e);
    }
    Info query(int l, int r) {
        l++, r++;
        return query(1, 1, n, l, r);
    }
};

class Info {
public:
    ...

    Info() {}
    Info(...) {
        ...
    }
};

Info operator+(const Info& a,const Info& b){
    Info c;
    ...
    return c;
}
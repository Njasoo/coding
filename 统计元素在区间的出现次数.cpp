namespace Rf {
    map<ll, vector<int>> pos;

    void build() {
        for(int i = 1; i <= n; i++) {
            pos[a[i]].push_back(i);
        }
    }

    int query(int l, int r, int val) {
        int pos1 = lower_bound(pos[val].begin(), pos[val].end(), l) - pos[val].begin();
        int pos2 = upper_bound(pos[val].begin(), pos[val].end(), r) - pos[val].begin();
        return pos2 - pos1;
    }
}
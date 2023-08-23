#include <bits/stdc++.h>

using namespace std;

// sum[r] - sum[l - 1] > 0 -> sum[r] > sum[l - 1], 也就是求正序对
// 坑点: 区间为1的情况

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

    int n;
    cin >> n;

    vector<pair<long long, int>> s(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        s[i] = {sum, i + 1};
    }   

    sort(s.begin(), s.end(), [&](auto i, auto j) {
        if (i.first == j.first) return i.second > j.second;
        return i.first < j.first;
    });

    Fenwick<long long> fen(n);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        fen.add(s[i].second, 1);
        if (s[i].first > 0) ans++;
        ans += fen.sum(s[i].second - 1);
    }

    cout << ans << '\n';

    return 0;
}
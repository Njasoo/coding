#include <bits/stdc++.h>

const int P = 998244353;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> t;
    Fenwick(int _n) : n(_n), t(_n + 1) {}
    int lowbit(int x) { return x & -x; }
    void add(int x, T k) {
        while (x <= n) {
            t[x] += k;
            x += lowbit(x);
        }
    }
    T sum(int x) {
        T res = 0;
        while (x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
       
    int n;
    std::cin >> n;

    Fenwick<int> fen(n);
    for (int i = 1; i <= n; i++) {
        fen.add(i, 1);
    }

    std::vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % P;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        ans = (ans + fen.sum(a - 1) * fac[n - 1 - i] % P) % P;
        fen.add(a, -1);
    }

    std::cout << ans + 1 << '\n';
    
    return 0;
}
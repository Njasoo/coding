#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int MOD = 1e9 + 7;

template<class T>
T power(T a, int64_t b) {
    assert(b >= 0);
    T res = 1;
    while (b) {
        if (b % 2) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

class ModInt {
private:
    int64_t _x;

public:
    int64_t val() {
        return normalize(_x);
    }

    int64_t normalize(int64_t x) {
        if (x >= MOD) x -= MOD;
        if (x < 0) x += MOD;
        return x;
    }

    ModInt() : _x(0) {}

    ModInt(int64_t rhs) {
        _x = normalize(rhs);
    }

    ModInt& operator=(int64_t rhs) {
        *this = ModInt(rhs);
        return *this;
    }

    ModInt operator+(int64_t rhs) {
        return ModInt(this->val() + rhs);
    }

    ModInt operator+(ModInt rhs) {
        return ModInt(this->val() + rhs.val());
    }

    ModInt& operator+=(int64_t rhs) {
        *this = *this + rhs;
        return *this;
    }

    ModInt& operator+=(ModInt rhs) {
        *this = *this + rhs.val();
        return *this;
    }

    ModInt& operator++(int) {
        *this += 1;
        return *this;
    }

    ModInt& operator++() {
        *this += 1;
        return *this;
    }

    ModInt operator*(int64_t rhs) {
        return ModInt(this->val() * rhs % MOD);
    }

    ModInt operator*(ModInt rhs) {
        return ModInt(this->val() * rhs.val() % MOD);
    }

    ModInt& operator*=(int64_t rhs) {
        *this = *this * rhs;
        return *this;
    }

    ModInt& operator*=(ModInt rhs) {
        *this = *this * rhs;
        return *this;
    }

    ModInt operator-(int64_t rhs) {
        return ModInt(this->val() - rhs);
    }

    ModInt operator-(ModInt rhs) {
        return ModInt(this->val() - rhs.val());
    }

    ModInt& operator-=(int64_t rhs) {
        *this = *this - rhs;
        return *this;
    }

    ModInt& operator-=(ModInt rhs) {
        *this = *this - rhs;
        return *this;
    }

    ModInt& operator--(int) {
        *this -= 1;
        return *this;
    }

    ModInt& operator--() {
        *this -= 1;
        return *this;
    }

    ModInt inv() {
        assert(_x != 0);
        return power(_x, MOD - 2);
    }

    ModInt operator/(int64_t rhs) {
        return ModInt(*this * ModInt(rhs).inv());
    }

    ModInt operator/(ModInt rhs) {
        return ModInt(*this / rhs.val());
    }

    ModInt& operator/=(int64_t rhs) {
        *this = *this / rhs;
        return *this;
    }

    ModInt& operator/=(ModInt rhs) {
        *this = *this / rhs;
        return *this;
    }

    friend istream& operator>>(istream& in, ModInt& rhs) {
        in >> rhs._x;
        return in;
    }

    friend ostream& operator<<(ostream& out, ModInt rhs) {
        out << rhs.val();
        return out;
    }

    friend bool operator==(ModInt lhs, int64_t rhs) {
        return lhs.val() == rhs;
    }

    friend bool operator==(ModInt lhs, ModInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend bool operator!=(ModInt lhs, int64_t rhs) {
        return !(lhs == rhs);
    }

    friend bool operator!=(ModInt lhs, ModInt rhs) {
        return !(lhs == rhs);
    }
};

using M = ModInt;

// class Comb {
// private:
//     int _n;
//     vector<M> _fac, _inv_fac;

// public:
//     Comb(int MAXN) : _n(MAXN), _fac(MAXN + 1), _inv_fac(MAXN + 1) {
//         _fac[0] = 1;
//         for (int i = 1; i <= MAXN; i++) {
//             _fac[i] = _fac[i - 1] * i;
//         }
//         _inv_fac[MAXN] = _fac[MAXN].inv();
//         for (int i = MAXN - 1; i >= 0; i--) {
//             _inv_fac[i] = _inv_fac[i + 1] * (i + 1);
//         }
//     }

//     M factorial(int n) {
//         assert(n >= 0 && n <= _n);
//         return _fac[n];
//     }

//     M C(int n, int k) {
//         if (k > n) return 0;
//         return _fac[n] * _inv_fac[n - k] * _inv_fac[k];
//     }
// };
// const int V = ...;
// Comb comb(V);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    int k;
    cin >> n >> m >> k;
    M ans = power(M(2), n - 1);
    ans = power(ans, m - 1);
    if ((n + m) % 2 && k == -1) cout << "0\n";
    else cout << ans << '\n';
    return 0;
}
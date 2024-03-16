#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

template<class T>
struct FenWick {
    int n;
    vector<T> tr;

    FenWick(int _n) : n(_n), tr(n) {}
    void update(int x, const T& k) {
        x++;
        while (x <= n) {
            tr[x - 1] += k;
            x += x & -x;
        }
    }
    T sum(int x) {
        x++;
        T res = 0;
        while (x) {
            res += tr[x - 1];
            x -= x & -x;
        }
        return res;
    }
    T query(int l, int r) {
        if (l > r) {
            return 0;
        }
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    FenWick<int> fen(N);
    vector<bool> s(N);
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) {
            fen.update(i, 1);
            s[i] = true;
        }
    }
    while (Q--) {
        int t, L, R;
        cin >> t >> L >> R;
        L--, R--;
        if (t == 1) {
            if (L > 0) {
                if (s[L]) {
                    fen.update(L, -1);
                } else {
                    fen.update(L, 1);
                }
                s[L] = !s[L];
            }
            if (R + 1 < N) {
                if (s[R + 1]) {
                    fen.update(R + 1, -1);
                } else {
                    fen.update(R + 1, 1);
                }
                s[R + 1] = !s[R + 1];
            }
        } else {
            if (fen.query(L + 1, R)) { // [L + 1, R]
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}
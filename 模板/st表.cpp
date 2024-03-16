#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>
#include <numeric>
#include <iomanip>
#include <set>
#include <array>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

const int N = 1e5 + 5, MN = 1e5;
int n;
int a[N];

template<class T>
struct SparseTable {
    int lg[N];
    T st[N][21];
    const T& (*func)(const T&, const T&);

    void init() {
        lg[0] = lg[1] = 0;
        for (int i = 2; i <= MN; i++) {
            lg[i] = lg[i / 2] + 1;
        }
    }
    SparseTable(const T arr[], const T& (*func)(const T&, const T&)) {
        init();
        this->func = func;
        for (int i = 1; i <= n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int k = lg[r - l + 1];
        return func(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    SparseTable<int> st(a, max);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
    return 0;
}
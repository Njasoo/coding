#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 500000;
int n, q;
long long t[N + 5];
int lowbit(int x) {
    return x & -x;
}
void add(int p, long long x) {
    while (p <= n) {
        t[p] += x;
        p += lowbit(p);
    }
}
long long query(int x) {
    long long res = 0;
    while (x) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        add(i, a);
    }   
    while (q--) {
        int op;
        cin >> op;
        if (!op) {
            int p, x;
            cin >> p >> x;
            p++;
            add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            l++;
            cout << query(r) - query(l - 1) << '\n';
        }
    }
    return 0;
}
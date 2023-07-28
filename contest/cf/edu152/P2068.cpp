#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1e5 + 5;
long long t[N];
int n, m;

void add(int x, long long k) {
    while (x <= n) {
        t[x] += k;
        x += x & -x;
    }
}

long long query(int x) {
    long long res = 0;
    while (x) {
        res += t[x];
        x -= x & -x;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'x') {
            add(a, b);
        } else {
            cout << query(b) - query(a - 1) << '\n';
        }
    }
    return 0;
}
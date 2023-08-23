#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 2e4 + 5;
int f[N], siz[N];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool merge(int x, int y) {
    if (same(x, y)) return 0;
    x = find(x), y = find(y);
    f[y] = x;
    siz[x] += siz[y];
    return 1;
}

int size(int x) {
    return siz[find(x)];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n + m; i++) {
        f[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        x = n - x, y = n - y;
        merge(x, y);
    }
    cout << min(size(1), size(1 + n)) << '\n';
    return 0;
}
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

const int N = 3e5 + 5;
struct Node {
    int l, r, id;
} t[N];
int tmp[N], tr[N];
int n;

void add(int x) {
    while (x <= n) {
        tr[x]++;
        x += x & -x;
    }
}

int sum(int x) {
    int res = 0;
    while (x) {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].l >> t[i].r;
        t[i].id = i;
        tmp[i] = t[i].r;
    }
    sort(tmp + 1, tmp + 1 + n);
    int len = unique(tmp + 1, tmp + 1 + n) - (tmp + 1);
    sort(t + 1, t + 1 + n, [&](auto i, auto j) {
        if (i.l == j.l) {
            return i.r > j.r;
        }
        return i.l < j.l;
    });
    for (int i = 1; i <= n; i++) {
        t[i].r = lower_bound(tmp + 1, tmp + 1 + len, t[i].r) - tmp;
    }
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (query(t[i].r, n)) {
            pos = i;
            break;
        }
        add(t[i].r);
    }
    if (!pos) {
        cout << "-1 -1\n";
        return 0;
    }
    int pos2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i == pos) continue;
        if (t[i].l <= t[pos].l && t[i].r >= t[pos].r) {
            pos2 = i;
            break;
        }
    }
    cout << t[pos].id << " " << t[pos2].id << '\n';
    return 0;
}

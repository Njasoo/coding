#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 2e5 + 5;
const long double pi = 4 * atan(1);
int n, ans[N];
ll val[N * 4];
ll L;
struct Node {
    int id, x, y, z;
    long double angle;
    ll d;
} t[N];

long double get(Node node) { 
    ll x = node.x, y = node.y;
    long double angle = atan((long double)llabs(y) / llabs(x));
    if (x >= 0 && y >= 0) {
        return pi / 2 - angle;
    } else if (x >= 0 && y < 0) {
        return pi / 2 + angle;
    } else if (x < 0 && y < 0) {
        return 3 * pi / 2 - angle;
    } else {
        return 3 * pi / 2 + angle;
    }
}

ll dis2(Node node) {
    int x = node.x, y = node.y;
    return 1LL * x * x + 1LL * y * y;
}

void build(int id, int l, int r) {
    if (l == r) {
        val[id] = t[l].d;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    val[id] = min(val[id * 2], val[id * 2 + 1]);
}

void remove(int id, int l, int r, int p) {
    if (l == r) {
        val[id] = 5e18;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) {
        remove(id * 2, l, mid, p);
    } else {
        remove(id * 2 + 1, mid + 1, r, p);
    }
    val[id] = min(val[id * 2], val[id * 2 + 1]);
}

ll query(int id, int l, int r, int s, int e) {
    if (s > e) {
        return 5e18;
    }
    if (r < s || l > e) {
        return 5e18;
    }
    if (s <= l && e >= r) {
        return val[id];
    }
    int mid = (l + r) / 2;
    return min(query(id * 2, l, mid, s, e), query(id * 2 + 1, mid + 1, r, s, e));
}

int find(int l, int r) { // find the first position in [l, r] such that the distance <= L, make sure min([l, r]) <= L * L
    int lo = l, hi = r;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (query(1, 1, n, lo, mid) <= L * L) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> L;       
    for (int i = 1; i <= n; i++) {
        t[i].id = i;
        ans[i] = -1;
        cin >> t[i].x >> t[i].y >> t[i].z;
        t[i].angle = get(t[i]);
        t[i].d = dis2(t[i]);
    }
    sort(t + 1, t + 1 + n, [&](auto i, auto j) {
        if (i.angle == j.angle) { // 先把距离长的，本来可以拿到的距离短的点，需要再绕好几圈才能拿到
            return i.d < j.d;
        }
        return i.angle < j.angle;
    });
    t[0].angle = -1;
    build(1, 1, n);
    // cerr << "hi" << endl;
    // exit(0);
    int cnt = 0, last = 0;
    while (cnt < n) {
        if (query(1, 1, n, last + 1, n) > L * L && query(1, 1, n, 1, last - 1) > L * L) {
            break;
        }
        int pos;
        if (query(1, 1, n, last + 1, n) <= L * L) {
            pos = find(last + 1, n);
        } else if (query(1, 1, n, 1, last - 1) <= L * L) {
            pos = find(1, last - 1);
        }
        cnt++;
        // db(t[pos].id), el;
        // x1 / y1 == x2 / y2
        // x1y2 - x2y1 == 0 这样只能代表共线，不能代表同向
        // ll x1 = t[pos].x, x2 = t[last].x;
        // ll y1 = t[pos].y, y2 = t[last].y;
        if (t[pos].angle == t[last].angle && last) { // 相信long double的精度
            ans[t[pos].id] = ans[t[last].id];
        } else {
            ans[t[pos].id] = cnt;
        }
        remove(1, 1, n, pos);
        L += t[pos].z;
        if (L > 2e9) {
            L = 2e9;
        }
        last = pos;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
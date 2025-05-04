#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 1e5 + 5;
int a[N], b[N], val[N * 4], dp1[N], dp2[N];
// 线段树求的是1 ~ a[i]中的最值

void clear(int id, int l, int r) {
    val[id] = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    clear(id * 2, l, mid);
    clear(id * 2 + 1, mid + 1, r);
}

void update(int id, int l, int r, int p, int x) {
    if (l == r) {
        val[id] = max(val[id], x);
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) {
        update(id * 2, l, mid, p, x);
    } else {
        update(id * 2 + 1, mid + 1, r, p, x);
    }
    val[id] = max(val[id * 2], val[id * 2 + 1]);
}

int query(int id, int l, int r, int s, int e) {
    if (r < s || l > e) {
        return 0;
    }
    if (s <= l && e >= r) {
        return val[id];
    }
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, s, e), query(id * 2 + 1, mid + 1, r, s, e));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }       
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    dp1[0] = 0;
    dp1[1] = 1;
    update(1, 1, n, a[1], dp1[1]);
    for (int i = 2; i <= n; i++) {
        int mx = query(1, 1, n, 1, a[i]);
        dp1[i] = mx + 1;
        update(1, 1, n, a[i], dp1[i]);
    }
    clear(1, 1, n);
    dp2[n + 1] = 0;
    dp2[n] = 1;
    update(1, 1, n, a[n], dp2[n]);
    for (int i = n - 1; i >= 1; i--) {
        int mx = query(1, 1, n, a[i], n);
        dp2[i] = mx + 1;
        update(1, 1, n, a[i], dp2[i]);
    }
    int ans = k;
    a[n + 1] = n;
    clear(1, 1, n);
    for (int j = k + 1; j <= n + 1; j++) {
        int i = j - k - 1;
        if (i >= 1) {
            update(1, 1, n, a[i], dp1[i]);
        }
        int mx = query(1, 1, n, 1, a[j]);
        // db(j), db(a[j]), db(mx), el;
        ans = max(ans, mx + k + dp2[j]);
    }
    cout << ans << '\n';
    return 0;
}
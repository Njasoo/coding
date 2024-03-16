#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 2e5 + 5;
#define int long long
int tr[N * 4], a[N];
int n, m;

void build(int id, int l, int r) {
    if (l == r) {
        tr[id] = a[l] % m;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tr[id] = tr[id * 2] * tr[id * 2 + 1] % m;
}

int query(int id, int l, int r, int s, int e) {
    if (l == s && r == e) {
        return tr[id] % m;
    }
    int mid = (l + r) / 2;
    if (e <= mid) return query(id * 2, l, mid, s, e) % m;
    else if (s > mid) return query(id * 2 + 1, mid + 1, r, s, e) % m;
    return query(id * 2, l, mid, s, mid) * query(id * 2 + 1, mid + 1, r, mid + 1, e) % m;
}

void solve(int test_no) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    build(1, 1, n);
    int l = 1, r = n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cout << query(1, 1, n, l, r) << " ";
        if (s[i] == 'L') l++;
        else r--;
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve(i);    
    }
    return 0;
}
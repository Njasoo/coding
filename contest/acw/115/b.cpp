#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 2e5 + 5;
long long w[N], h[N], t[N << 2];

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = h[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = max(t[id << 1], t[id << 1 | 1]);
}

long long query(int id, int l, int r, int s, int e) {
    if (s > e) return 0;
    if (l == s && r == e) {
        return t[id];
    }
    int mid = (l + r) / 2;
    if (e <= mid) return query(id << 1, l, mid, s, e);
    else if (s > mid) return query(id << 1 | 1, mid + 1, r, s, e);
    else return max(query(id << 1, l, mid, s, mid), query(id << 1 | 1, mid + 1, r, mid + 1, e));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long sumw = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
        sumw += w[i];
    }
    build(1, 1, n);
    long long totw = sumw - w[1];
    long long maxH = query(1, 1, n, 2, n);
    // db(maxH);
    cout << totw * maxH << " ";
    for (int i = 2; i < n; i++) {
        long long totw = sumw - w[i];
        long long maxH = max(query(1, 1, n, 1, i - 1), query(1, 1, n, i + 1, n));
        cout << totw * maxH << " ";
    }
    totw = sumw - w[n];
    maxH = query(1, 1, n, 1, n - 1);
    cout << totw * maxH << '\n';
    return 0;
}
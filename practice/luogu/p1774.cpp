#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long t[N];
pair<int, int> a[N]; // (id, val)
int n;
int lowbit(int x) {
    return (x & -x);
}
void add(int x) {
    while (x <= n) {
        t[x]++;
        x += lowbit(x);
    }
}
long long query(int x) {
    int res = 0;
    while (x) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
        a[i].first = i;
    }
    sort(a + 1, a + 1 + n, [&](pair<int, int> i, pair<int, int> j) {
        if (i.second == j.second) return i.first > j.first;
        return i.second > j.second;
    });
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        add(a[i].first);
        cnt += query(a[i].first - 1);
    }
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

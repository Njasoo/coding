#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long t[N];
pair<int, int> a[N];
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
    long long res = 0;
    while (x) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}
bool cmp(pair<int, int> i, pair<int, int> j) {
    if (i.second == j.second) return i.first > j.first;
    return i.second > j.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
        a[i].first = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        add(a[i].first);
        ans += query(a[i].first - 1);
    }
    cout << ans << '\n';
    return 0;
}

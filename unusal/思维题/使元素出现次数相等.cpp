#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define vt vector
#define sz(x) (int) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

/*
先写计算式, 在想办法优化
方法大多数都是前缀和
学到的新方法, 解决这种同一个数列里面, 有多少个元素大于某一个元素, 直接排序就行
*/

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    map<int, int> hs;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hs[a[i]]++;
    }
    vt<int> c;
    for (auto x : hs) {
        c.pb(x.se);
    }
    int sum = 0;
    for (int i = 0; i < sz(c); i++) {
        sum += c[i];
    }
    int ans = n;
    sort(all(c));
    for (int i = 0; i < sz(c); i++) {
        ans = min(ans, sum - (sz(c) - i) * c[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
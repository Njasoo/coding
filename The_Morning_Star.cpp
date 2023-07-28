#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// 四个方向独立开来

const int N = 2e5 + 5;
long long x[N], y[N];

void solve() {
    int n;
    cin >> n;
    map<long long, long long> shuiping, chuizhi, zhengxie, fanxie;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        shuiping[x[i]]++;
        chuizhi[y[i]]++;
        zhengxie[x[i] - y[i]]++;
        fanxie[x[i] + y[i]]++;
    }
    long long ans = 0;
    for (auto [xx, yy] : shuiping) {
        ans += yy * (yy - 1);
    }
    for (auto [xx, yy] : chuizhi) {
        ans += yy * (yy - 1);
    }
    for (auto [xx, yy] : zhengxie) {
        ans += yy * (yy - 1);
    }
    for (auto [xx, yy] : fanxie) {
        ans += yy * (yy - 1);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
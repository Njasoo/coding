#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// 数轮攻击后, 所有怪物的血量都是k的余数, 谁的余数大谁先死

const int N = 3e5 + 5;
pair<int, int> a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].first %= k;
        if (a[i].first == 0) a[i].first = k;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, [&](auto i, auto j) -> bool {
        if (i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    });
    for (int i = 1; i <= n; i++) {
        cout << a[i].second << " \n"[i == n];
    }
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
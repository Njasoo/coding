#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// 有效区间, 会发生改变的区间, 区间内的第一个1到最后一个0位置
// 在前面的0, 和在后面的1, 排序后不影响结果

const int N = 2e5 + 5;
int lst[N], nxt[N]; // lst[i]: i之前最后一个零的位置, nxt[i]: i之后开始第一个一的位置

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    set<pair<int, int>> S;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') lst[i] = i;
        else lst[i] = lst[i - 1];
    }
    nxt[n + 1] = 1e9;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1') nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        l = nxt[l], r = lst[r];
        if (l > r) {
            l = r = 0;
        }
        S.insert({l, r});
    }
    cout << S.size() << '\n';
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
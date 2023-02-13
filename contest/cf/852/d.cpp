#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
// 容斥
const int N = 2e5 + 5;
int n;
int p[N], q[N], posp[N], posq[N];
long long calc(int l, int r) {
    long long len = r - l + 1;
    if (len < 0) return 0;
    return len * (len + 1) / 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        posp[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        posq[q[i]] = i;
    }
    int nowL = min(posp[1], posq[1]);
    int nowR = max(posp[1], posq[1]);
    long long ans = calc(1, nowL - 1) + calc(nowL + 1, nowR - 1) + calc(nowR + 1, n);
    // debug(ans);
    int legalL = nowL;
    int legalR = nowR;
    for (int i = 2; i <= n; i++) {
        nowL = min(posp[i], posq[i]);
        nowR = max(posp[i], posq[i]);
        if (nowR < legalL) { // 都在左边
            ans += calc(nowR + 1, n) - calc(legalL + 1, n) - calc(nowR + 1, legalR - 1) + calc(legalL + 1, legalR - 1);
        } else if (nowL > legalR) { // 都在右边
            ans += calc(1, nowL - 1) - calc(1, legalR - 1) - calc(legalL + 1, nowL - 1) + calc(legalL + 1, legalR - 1);
        } else if (nowL < legalL && nowR > legalR) { // 在两边
            ans += calc(nowL + 1, nowR - 1) - calc(nowL + 1, legalR - 1) - calc(legalL + 1, nowR) + calc(legalL + 1, legalR - 1);
        }
        legalL = min(legalL, nowL);
        legalR = max(legalR, nowR);
    }
    cout << ans + 1 << '\n'; // 加上 mex == n + 1 的情况
    return 0;
}
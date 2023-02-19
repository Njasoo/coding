#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
// 组合
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
    long long nowL = min(posp[1], posq[1]);
    long long nowR = max(posp[1], posq[1]);
    long long ans = calc(1, nowL - 1) + calc(nowL + 1, nowR - 1) + calc(nowR + 1, n);
    // cerr << "ans: " << ans << endl;
    // debug(ans);
    long long legalL = nowL;
    long long legalR = nowR;
    for (int i = 2; i <= n; i++) {
        nowL = min(posp[i], posq[i]);
        nowR = max(posp[i], posq[i]);
        // cerr << "nowL = " << nowL << " " << "nowR = " << nowR << endl;
        if (nowR < legalL) { // 都在左边
            ans += (legalL - nowR) * (n - legalR + 1);
            // cerr << "nowL: " << nowL << " " << "nowR: " << nowR << endl;
            // cerr << "legalL: " << legalL << " " << "legalR: " << legalR << endl;
            // debug((legalL - nowL) * (n - legalR + 1));
        } else if (nowL > legalR) { // 都在右边
            ans += (nowL - legalR) * legalL;
            // debug((nowL - legalR) * legalL);
        } else if (nowL < legalL && nowR > legalR) { // 在两边
            ans += (legalL - nowL) * (nowR - legalR);
            // debug((legalL - nowL) * (nowR - legalR));
        }
        // cerr << "ans: " << ans << endl;
        legalL = min(legalL, nowL);
        legalR = max(legalR, nowR);
        // cerr << "legalL: " << legalL << " " << "legalR: " << legalR << endl;
    }
    cout << ans + 1 << '\n'; // 加上 mex == n + 1 的情况
    return 0;
}

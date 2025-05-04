#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e5 + 5;
int a[N], b[N], n, m;

bool check(int d) { // 所有值都要<=d
    i64 cnt = 0;
    // a[i] - k * b[i] <= d
    // k >= (a[i] - d) / b[i]
    for (int i = 1; i <= n; i++) {
        cnt += max(0, (a[i] - d + b[i] - 1) / b[i]);
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }   
    int lo = 0, hi = 1e6;
    int bans = 1e6;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            bans = mid;
        } else {
            lo = mid + 1;
        }
    }
    // db(bans), el;
    i64 ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int k = max(0, (a[i] - bans + b[i] - 1) / b[i]);
        // a[i] + a[i] - b[i] + a[i] - 2 * b[i] + ... + a[i] - (k - 1) * b[i]
        // = k * a[i] - (k * b[i] * (k - 1) / 2)
        ans += 1LL * k * a[i] - (1LL * k * (k - 1) * b[i] / 2);
        a[i] -= k * b[i];
        cnt += k;
    }
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        q.emplace(a[i], i);
    }
    while (!q.empty() && cnt < m) {
        auto [x, y] = q.top();
        q.pop();
        ans += x;
        x -= b[y];
        if (x > 0) {
            q.emplace(x, y);
        }
        cnt++;
    }
    cout << ans << '\n';
    return 0;
}
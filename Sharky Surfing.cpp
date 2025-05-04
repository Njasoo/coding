#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

const int N = 2e5 + 5;
int n, m, L;
int l[N], r[N], x[N], v[N], need[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m >> L;
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
            need[i] = r[i] - l[i] + 1;
        }
        for (int i = 1; i <= m; i++) {
            cin >> x[i] >> v[i];
        }
        int i = 1, j = 1;
        priority_queue<int> q;
        i64 cur = 0;
        int ans = 0;
        while (i <= n) {
            while (j <= m && x[j] < l[i]) {
                q.push(v[j]);
                j++;
            }
            while (!q.empty() && cur < need[i]) {
                ans++;
                cur += q.top();
                q.pop();
            }
            if (cur < need[i]) {
                ans = -1;
                break;
            }
            i++;
        }
        cout << ans << '\n';
    }   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N], cnt[N];
vector<int> factors[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= MN; i++) {
        for (int j = i; j <= MN; j += i) {
            factors[j].push_back(i);
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int j = 1, tot = 0;
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            j = max(j, i);
            while (j <= n && tot < m) {
                for (int factor : factors[a[j]]) {
                    if (factor > m) break;
                    cnt[factor]++;
                    if (cnt[factor] == 1) tot++;
                }
                j++;
            }
            if (tot < m) break;
            ans = min(ans, a[j - 1] - a[i]);
            for (int factor : factors[a[i]]) {
                if (factor > m) break;
                cnt[factor]--;
                if (cnt[factor] == 0) tot--;
            }
        }
        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int ans[N], cnt[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int tempi = i;
        for (int j = 2; tempi != 1; j++) { // 晒出来的肯定是质数，问就是数论
            while (tempi % j == 0) {
                cnt[j]++;
                if (cnt[j] == 1) ans[++idx] = j;
                tempi /= j;
            }
        }
    }       
    sort(ans + 1, ans + 1 + idx);
    for (int i = 1; i <= idx; i++) {
        cout << ans[i] << " " << cnt[ans[i]] << '\n';
    }
    return 0;
}
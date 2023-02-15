#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 6;
const int MN = 1e6;
bool vis[N];
int primes[N], cnt[N];
int tot;
void sieve() {
    vis[1] = 1;
    for (int i = 2; i <= MN; i++) {
        if (!vis[i]) primes[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * primes[j] > MN) break;
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cnt[i] = cnt[i - 1] + !vis[i];
    }
    while (n--) {
        int l, r;
        cin >> l >> r;
        if (l < 1 || l > m || r < 1 || r > m) {
            cout << "Crossing the line\n";
        } else {
            cout << cnt[r] - cnt[l - 1] << '\n';
        }
    }
    return 0;
}
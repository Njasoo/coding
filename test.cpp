#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5;
const int N = 1e5 + 5;
int tot;
int primes[N], n_prime_factors[N], cnt[N], ans[N];
bool vis[N];
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
    int n;
    cin >> n;
    int num = 1, idx = 0;
    for (int i = 2; i <= n; i++) num *= i;
    for (int i = 1; i <= tot; i++) {
        while (num % primes[i] == 0) {
            num /= primes[i];
            cnt[primes[i]]++;
            if (cnt[primes[i]] == 1) ans[++idx] = primes[i];
        }
    }
    sort(ans + 1, ans + 1 + idx);
    for (int i = 1; i <= idx; i++) {
        cout << ans[i] << " " << cnt[ans[i]] << '\n';
    }
    return 0;
}
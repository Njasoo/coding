#include <bits/stdc++.h>
using namespace std;
const int MN = 3e4;
const int N = 3e4 + 5;
const int INF = 0x3f3f3f3f;
int primes[N], m_prime_factor[N], cnt[N], a[N];
int tot, n, ans = INF, index_of_m_prime_factor, m1, m2;
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
    cin >> n;
    cin >> m1 >> m2;
    for (int i = 1; i * i <= m1; i++) {
        if (m1 % i == 0) {
            int j = m1 / i;
            int tempm1 = m1;
            while (tempm1 % i == 0 && !vis[i]) {
                cnt[i]++;
                if (cnt[i] == 1) m_prime_factor[++index_of_m_prime_factor] = i;
                tempm1 /= i;
            }
            while (tempm1 % j == 0 && !vis[j]) {
                cnt[j]++;
                if (cnt[j] == 1) m_prime_factor[++index_of_m_prime_factor] = j;
                tempm1 /= j;
            }
        }
    }
    for (int i = 1; i <= index_of_m_prime_factor; i++) {
        cnt[m_prime_factor[i]] *= m2;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 判断s[i]是否包含m1的质因数，可以通过mod每一个质因数看是否为零
    for (int i = 1; i <= n; i++) {
        bool flag = 1;
        for (int j = 1; j <= index_of_m_prime_factor; j++) {
            if (a[i] % m_prime_factor[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            int this_ans = 0;
            for (int j = 1; j <= index_of_m_prime_factor; j++) {
                int cnt_this_factor_power = 0;
                while (a[i] % m_prime_factor[j] == 0) {
                    cnt_this_factor_power++;
                    a[i] /= m_prime_factor[j];
                }
                // 啊啊啊，不是自乘啊，搞了我好多个小时啊啊啊啊啊啊啊啊
                this_ans = max(this_ans, cnt[m_prime_factor[j]] / cnt_this_factor_power + (cnt[m_prime_factor[j]] % cnt_this_factor_power != 0));
            }
            ans = min(ans, this_ans);
        }
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}
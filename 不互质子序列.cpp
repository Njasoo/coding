#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 1e5 + 5, MN = 1e5;
int a[N], dp[N];
bool isprime[N];
vector<int> prime_factors[N], primes;
priority_queue<int> q[N]; // q[i]: 包含有i这个素因子的dp[x]堆

void sieve() {
    for (int i = 2; i <= MN; i++) isprime[i] = true;
    for (int i = 2; i <= MN; i++) {
        if (isprime[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p > MN) break;
            isprime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    for (int i = 2; i <= MN; i++) {
        if (!isprime[i]) continue;
        for (int j = i; j <= MN; j += i) {
            prime_factors[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }       
    int ans = 1;
    dp[a[1]] = 1;
    for (int prime_factor : prime_factors[a[1]]) {
        q[prime_factor].push(dp[a[1]]);
    }
    for (int i = 2; i <= n; i++) {
        dp[a[i]] = 1;
        for (auto prime_factor : prime_factors[a[i]]) {
            if (!q[prime_factor].empty()) {
                dp[a[i]] = max(dp[a[i]], q[prime_factor].top() + 1);
            }
        }
        ans = max(ans, dp[a[i]]);
        for (auto prime_factor : prime_factors[a[i]]) {
            q[prime_factor].push(dp[a[i]]);
        }
    }
    cout << ans << '\n';
    return 0;
}
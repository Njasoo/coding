#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// 每个大于1的数都可以分解成2和3的线性组合
// 分成两堆或者一堆
// x^4 <= 10^18
// 把10000以内的素数都筛掉，然后判断剩下的是不是一个平方数或者立方数，不需要判断四次方的，因为如果是四次方的，一定是一种素数或者两种素数
const int N = 1e4 + 5, MN = 1e4;
bool isprime[N];
vector<int> primes;

void sieve() {
    for (int i = 2; i <= MN; i++) isprime[i] = true;
    for (int i = 2; i <= MN; i++) {
        if (isprime[i]) primes.push_back(i);
        for (auto p : primes) {
            if (i * p > MN) break;
            isprime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

bool issq(ll x) {
    ll bans = 1;
    ll lo = 1, hi = 1e9;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (mid * mid <= x) {
            lo = mid + 1;
            bans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return bans * bans == x;
}

bool islf(ll x) {
    ll bans = 1;
    ll lo = 1, hi = 1e6;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (mid * mid * mid <= x) {
            lo = mid + 1;
            bans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return bans * bans * bans == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        bool flag = true;
        for (auto p : primes) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            if (cnt == 1) {
                flag = false;
                break;
            }
            if (n == 1) break;
        }
        if (!flag) {
            cout << "no\n";
            continue;
        }
        if (issq(n) || islf(n)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
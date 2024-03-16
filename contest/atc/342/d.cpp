#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (p * i > n) {
                break;
            }
            minp[p * i] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(2e5);
    int N;
    cin >> N;
    map<int, int> f;
    i64 ans = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (A == 0) {
            cnt++;
            continue;
        }
        for (auto p : primes) {
            if (p * p > A) {
                break;
            }
            while (A % (p * p) == 0) {
                A /= (p * p);
            }
        }
        ans += f[A]++;
    }      
    ans += 1LL * cnt * (N - cnt);
    ans += 1LL * cnt * (cnt - 1) / 2;
    cout << ans << '\n';
    return 0;
}
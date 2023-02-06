#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int notprime[N], prime[N];

int main() {
    notprime[1] = notprime[0] = 1;
    for (int i = 2; i <= sqrt(N); i++) {
        for (int j = 2; i * j <= N; j++) {
            notprime[i * j] = 1;
        }
    }
    int index = 0;
    map<int, int> mp;
    for (int i = 1; i < N; i++) {
        if (notprime[i] == 0) {
            prime[++index] = i;
            mp[i] = index;
        }
    }
    int n, m;
    cin >> n >> m;
    if (prime[mp[n] + 1] == m) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}
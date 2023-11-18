#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int MN = 1e5;
const int N = 1e5 + 5;
vector<int> factors[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i <= MN; i++) {
        for (int j = i; j <= MN; j += i) {
            factors[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int factor : factors[a]) {
            cnt[factor]++;
            ans = max(ans, cnt[factor]);
        }
    }
    cout << ans << '\n';
    return 0;
}
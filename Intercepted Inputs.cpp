#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

const int N = 2e5 + 5;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        k -= 2;
        pair<int, int> ans = {-1, -1};
        for (int i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                int n = i;
                int m = k / i;
                if (n == m) {
                    if (cnt[n] >= 2) {
                        ans = {n, m};
                        break;
                    }
                } else {
                    if (cnt[n] && cnt[m]) {
                        ans = {n, m};
                        break;
                    }
                }
            }
        }
        cout << ans.first << " " << ans.second << '\n';
    }   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

int cnt[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += cnt[i] / 2;
        }
        cout << ans << '\n';
    }   
    return 0;
}
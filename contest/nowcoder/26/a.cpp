#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a % k]++;
        ans = max(ans, cnt[a % k]);
    }   
    cout << ans << '\n';
    return 0;
}
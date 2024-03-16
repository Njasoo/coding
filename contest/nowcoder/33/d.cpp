#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] += 1;
        tot += 1;
    }   
    sort(a.begin(), a.end());
    int ans = 0;
    int p = 0;
    while (tot) {
        ans += 1;
        while (cnt[a[p]] == 0) {
            p += 1;
        }
        int x = a[p];
        cnt[x] -= 1;
        tot -= 1;
        while (true) {
            if (cnt[x + 1] == 0) {
                break;
            }
            cnt[x + 1] -= 1;
            tot -= 1;
            x += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
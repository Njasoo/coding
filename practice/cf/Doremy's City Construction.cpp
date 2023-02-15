#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 5;
int a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        a[n + 1] = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i + 1]) {
                ans = max(ans, 1LL * i * (n - i));
            }
        }
        vector<int> new_a(1);
        long long cnt2 = 0;
        for (auto [x, y] : cnt) {
            if (y % 2 == 1) {
                new_a.push_back(x);
            }
            cnt2 += y / 2;
        }
        int len_of_new_a = new_a.size() - 1;
        for (int i = 1; i <= len_of_new_a; i++) {
            cnt2 = max(cnt2, 1LL * i * (len_of_new_a - i));
        }
        cout << max(ans, cnt2) << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

const int N = 1e5 + 5;
pair<int, int> a[N];
int ans[N], n;

bool check(int d, int i) {
    int p1 = n + 1, p2 = 0;
    {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid].first > d) {
                hi = mid - 1;
                p1 = mid;
            } else {
                lo = mid + 1;
            }
        }
    }
    {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid].first < d) {
                lo = mid + 1;
                p2 = mid;
            } else {
                hi = mid - 1;
            }
        }
    }
    int cnt1 = n - p1 + 1;
    if (a[i].first > d) {
        cnt1--;
    } else if (a[i].first < d) {
        p2--;
    }
    return cnt1 <= p2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }   
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int lo = a[i].first, hi = 100000;
        int bans = a[i].first;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, i)) {
                hi = mid - 1;
                bans = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans[a[i].second] = bans - a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
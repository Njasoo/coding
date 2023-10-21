#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 2e5 + 5;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }   
    sort(b + 1, b + 1 + n);
    map<int, int64_t> cntl, cntr;
    for (int i = 3; i <= n; i++) {
        cntr[a[i]]++;
    }
    cntl[a[1]]++;
    int64_t ans = 0;
    for (int i = 2; i < n; i++) {
        set<int> s;
        s.insert(b[1]);
        s.insert(b[2]);
        s.insert(b[3]);
        for (int x : s) {
            if (a[i] == x) {
                if (x == b[1]) {
                    ans += cntl[b[2]] * cntr[b[3]];
                    if (b[2] != b[3]) ans += cntl[b[3]] * cntr[b[2]];
                } else if (x == b[2]) {
                    ans += cntl[b[1]] * cntr[b[3]];
                    if (b[1] != b[3]) ans += cntl[b[3]] * cntr[b[1]];
                } else if (x == b[3]) {
                    ans += cntl[b[1]] * cntr[b[2]];
                    if (b[1] != b[2]) ans += cntl[b[2]] * cntr[b[1]];
                }
            }
        }
        cntl[a[i]]++;
        cntr[a[i + 1]]--;
    }
    cout << ans << '\n';
    return 0;
}
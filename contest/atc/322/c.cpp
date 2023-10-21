#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 2e5 + 5;
bool tag[N];
int ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        tag[a] = 1;
    }   
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (tag[i]) {
            cnt = 0;
            continue;
        }
        ans[i] = ++cnt;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
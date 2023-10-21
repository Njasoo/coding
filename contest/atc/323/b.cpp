#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 105;
pair<int, int> t[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t[i].second = i;
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'o') {
                t[i].first++;
            } else if (ch == 'x') {
                t[j].first++;
            }
        }
    }
    sort(t + 1, t + 1 + n, [&](auto i, auto j) -> bool {
        if (i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    });
    for (int i = 1; i <= n; i++) {
        cout << t[i].second << " \n"[i == n];
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int s[N], w[N];
pair<int, int> t[N];
int read() {
    int x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0', ch = getchar();
    }
    return x * f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = read(), r = read(), q = read();
    for (int i = 1; i <= n * 2; i++) {
        s[i] = read();
    }      
    for (int i = 1; i <= n * 2; i++) {
        w[i] = read();
    }
    for (int i = 1; i <= n * 2; i++) {
        t[i] = {s[i], i};
    }
    for (int k = 1; k <= r; k++) {
        sort(t + 1, t + 1 + n * 2, [&](auto i, auto j) {
            if (i.first == j.first) return i.second < j.second;
            return i.first > j.first;
        });
        for (int i = 1; i <= n * 2; i += 2) {
            int p1 = w[t[i].second];
            int p2 = w[t[i + 1].second];
            if (p1 > p2) {
                t[i].first++;
            } else {
                t[i + 1].first++;
            }
        }
    }
    sort(t + 1, t + 1 + n * 2, [&](auto i, auto j) {
        if (i.first == j.first) return i.second < j.second;
        return i.first > j.first;
    });
    cout << t[q].second << '\n';
    return 0;
}
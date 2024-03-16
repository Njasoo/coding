#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>
#include <numeric>
#include <iomanip>
#include <set>
#include <array>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

const int N = 3e5 + 5, MN = 3e5;
int a[N], st1[N][21], st2[N][21], lg[N];
int n;

void init() {
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= MN; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

void build1() {
    for (int i = 1; i <= n; i++) {
        st1[i][0] = a[i];
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st1[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void build2() {
    for (int i = 1; i <= n; i++) {
        st2[i][0] = a[i];
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query1(int l, int r) {
    int k = log2(r - l + 1);
    return min(st1[l][k], st1[r - (1 << k) + 1][k]);
}

int query2(int l, int r) {
    int k = lg[r - l + 1];
    return max(st2[l][k], st2[r - (1 << k) + 1][k]);
}

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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    init();
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    build1();
    build2();
    int i = 1;
    int ans = 0;
    while (i <= n) {
        int l = i, r = n;
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query1(i, mid) >= a[i]) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        int rpos = 0;
        l = i, r = pos;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (l == r) {
                rpos = l;
                break;
            }
            if (query2(mid + 1, r) == query2(i, pos)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        // db(i), db(rpos), el;
        i = rpos + 1;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
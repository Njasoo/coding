#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const int N = 1e6 + 5;
struct Node {
    long long x, y;
    int id;
} t[N], temp[N];
int n;
// 同类的距离设置为无穷大

bool cmp1(Node i, Node j) {
    return i.x < j.x;
}

bool cmp2(Node i, Node j) {
    return i.y < j.y;
}

double dis(Node i, Node j) {
    return sqrtl((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
}

long long my_abs(long long x) {
    return x >= 0 ? x : -x;
}

double solve(int l, int r) {
    if (l == r) return 1e18;
    int mid = l + (r - l) / 2;
    double d = min(solve(l, mid), solve(mid + 1, r));
    long long mid_line = t[mid].x;
    int L = l, R = mid + 1;
    int idx = l;
    while (idx <= r) {
        if (L == mid + 1) {
            temp[idx++] = t[R++];
            continue;
        }
        if (R == r + 1) {
            temp[idx++] = t[L++];
            continue;
        }
        if (t[L].y <= t[R].y) {
            temp[idx++] = t[L++];
        } else {
            temp[idx++] = t[R++];
        }
    }
    for (int i = l; i <= r; i++) {
        t[i] = temp[i];
    }
    idx = 0;
    for (int i = l; i <= r; i++) {
        if (my_abs(t[i].x - mid_line) < d) {
            temp[++idx] = t[i];
        }
    }
    for (int i = 1; i <= idx; i++) {
        for (int j = i + 1; j <= idx; j++) {
            if (temp[j].y - temp[i].y > d) break;
            if (temp[j].id == temp[i].id) continue;
            d = min(d, dis(temp[i], temp[j]));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            if (i <= n) t[i].id = 1;
            else t[i].id = 2;
            cin >> t[i].x >> t[i].y;
        }
        sort(t + 1, t + 1 + 2 * n, cmp1);
        cout << fixed << setprecision(3) << solve(1, 2 * n) << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
int n;
struct Node {
    long long x, y;
} p[N], temp[N];

long long dis_2(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool cmp1(Node i, Node j) {
    return i.x < j.x;
}

bool cmp2(Node i, Node j) {
    return i.y < j.y;
}

long long solve(int l, int r) {
    if (l == r)
        return (long long)1e18;
    int mid = (l + r) / 2;
    long long d = min(solve(l, mid), solve(mid + 1, r));
    int idx = 0;
    double sq = sqrt(d);
    for (int i = l; i <= r; i++) {
        if (fabs(p[i].x - p[mid].x) < sq) {
            temp[++idx] = p[i];
        }
    }
    sort(temp + 1, temp + 1 + idx, cmp2);
    long long res = d;
    for (int i = 1; i <= idx; i++) {
        for (int j = i + 1; j <= idx; j++) {
            if (temp[j].y - temp[i].y >= sq)
                break;
            res = min(res, dis_2(temp[i].x, temp[i].y, temp[j].x, temp[j].y));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + 1 + n, cmp1);
    cout << solve(1, n) << '\n';
    return 0;
}
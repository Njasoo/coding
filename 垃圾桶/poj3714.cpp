#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e6 + 5;
struct Node {
    double x, y;
    int id;
} t[N], temp[N];
// 同类的距离设置为无穷大

bool cmp1(Node i, Node j) {
    return i.x < j.x;
}

bool cmp2(Node i, Node j) {
    return i.y < j.y;
}

double dis(Node i, Node j) {
    return sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
}

double solve(int l, int r) {
    if (l == r) return 1e100;
    int mid = l + (r - l) / 2;
    double d = min(solve(l, mid), solve(mid + 1, r));
    int idx = 0;
    for (int i = l; i <= r; i++) {
        if (fabs(t[i].x - t[mid].x) < d) {
            temp[++idx] = t[i];   
        }
    }
    sort(temp + 1, temp + 1 + idx, cmp2);
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
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            if (i <= n) t[i].id = 1;
            else t[i].id = 2;
            scanf("%lf %lf", &t[i].x, &t[i].y);
        }
        sort(t + 1, t + 1 + 2 * n, cmp1);
        printf("%.3lf\n", solve(1, 2 * n));
    }
    return 0;
}
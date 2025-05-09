
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define db(x) cerr << #x << "=" << (x) << endl
#define N 1000005
#define M 500005
#define MN 1000000
#define LOG 20
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

long long a[N], temp[N];
long long ans;

void merge(int l1, int r1, int l2, int r2) {
    int p = l1;
    int pa = l1, pb = l2;
    while (p <= r2) {
        if (pa == r1 + 1) {
            temp[p++] = a[pb++];
            continue;
        }
        if (pb == r2 + 1) {
            temp[p++] = a[pa++];
            continue;
        }
        if (a[pa] <= a[pb])
            temp[p++] = a[pa++];
        else
            temp[p++] = a[pb++], ans += r1 - pa + 1;
    }
    for (int i = l1; i <= r2; i++)
        a[i] = temp[i];
}

void merge_sort(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    merge_sort(1, n);
    cout << ans << '\n';
    return 0;
}
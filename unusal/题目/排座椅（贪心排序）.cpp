#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
struct node {
    int x1, y1, x2, y2;
}t[N];
struct node2 {
    int id, fre;
}row[N], col[N];
bool cmp(node2 i, node2 j) {
    return i.fre > j.fre;
}
bool cmp2(node2 i, node2 j) {
    return i.id < j.id;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    for (int i = 1; i <= d; i++) {
        cin >> t[i].x1 >> t[i].y1 >> t[i].x2 >> t[i].y2;
    }       
    for (int i = 1; i <= n; i++) row[i].id = i;
    for (int i = 1; i <= m; i++) col[i].id = i;
    for (int i = 1; i <= d; i++) {
        if (t[i].x1 == t[i].x2) {
            col[min(t[i].y1, t[i].y2)].fre++;
        } else {
            row[min(t[i].x1, t[i].x2)].fre++;
        }
    }
    sort(row + 1, row + 1 + n, cmp);
    sort(col + 1, col + 1 + m, cmp);
    sort(row + 1, row + 1 + k, cmp2);
    sort(col + 1, col + 1 + l, cmp2);
    for (int i = 1; i <= k; i++) {
        cout << row[i].id << " \n"[i == k];
    }
    for (int i = 1; i <= l; i++) {
        cout << col[i].id << " \n"[i == l];
    }
    return 0;
}
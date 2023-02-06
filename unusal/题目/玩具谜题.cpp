#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct node {
    int head;
    string name;
}a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].head >> a[i].name;
    }
    int now = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (a[now].head == 0 && x == 0) {
            now = (now + n - y) % n; // 避免变成负数
        } else if (a[now].head == 0 && x == 1) {
            now = (now + y) % n;
        } else if (a[now].head == 1 && x == 0) {
            now = (now + y) % n;
        } else if (a[now].head == 1 && x == 1) {
            now = (now + n - y) % n;
        }
    }
    cout << a[now].name << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
struct edge {
    int to, next;
}e[N << 1];
int cnt;
int head[N];
void add_edge(int u, int v) {
    cnt++;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int d1[N], d2[N];
int maxv;
void dfs(int u, int fa, int d[]) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa) continue;
        d[v] = d[u] + 1;
        if (d[v] > d[maxv]) maxv = v;
        dfs(v, u, d);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }   
    dfs(1, 0, d1);
    dfs(maxv, 0, d2);
    cout << d2[maxv] << '\n';
    return 0;
}
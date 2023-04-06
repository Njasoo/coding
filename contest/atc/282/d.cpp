#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

const int N = 2e5 + 5;
int n, m;
int f[N], cloor[N];
vector<int> p[N];
bool vis[N];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    f[y] = x;
}

bool flag = 1;
void dfs(int u, int c) {
    vis[u] = 1;
    cloor[u] = c;
    for (auto v : p[u]) {
        if (vis[v]) {
            if (cloor[v] == cloor[u]) {
                flag = 0;
            }
            continue;
        }
        dfs(v, c ^ 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            db(i);
            dfs(i, 1);
        }
    }
    if (!flag) {
        cout << "0\n";
        return 0;
    }
    int cntb = 0, cntw = 0;
    for (int i = 1; i <= n; i++) {
        if (cloor[i]) cntb++;
        else cntw++;
    }
    long long ans = 1LL * cntb * cntw - m;
    cout << ans << '\n';
    return 0;
}
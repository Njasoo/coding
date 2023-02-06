#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500005;
const int LOG = 19;
vector<int> p[MAX_N];
int vis[MAX_N], depth[MAX_N], up[MAX_N][LOG]; // up[i][j]: the 2^jth ancestor fo i

void dfs(int u) {
    vis[u] = 1;
    for (int v : p[u]) {
        if (!vis[v]) {
            up[v][0] = u;
            depth[v] = depth[u] + 1;
            for (int j = 1; j < LOG; j++) {
                up[v][j] = up[up[v][j - 1]][j - 1]; // 2^(j) = 2^(j-1)+2^(j-1)
            }
            dfs(v);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b]; // 假如k=10, 二进制为1010, 那么需要跳到第2^3和2^1个祖先
    for (int j = 0; (1 << j) <= k; j++) {
        if (k & (1 << j)) { // 检查从右边开始, k的第(j+1)位是否为1
            a = up[a][j];
        }
    } // 跳完深度就相同了
    if (a == b) {
        return a;
    }
    for (int j = LOG - 1; j >= 0; j--) { // 先填小的就填不上大的, 所以倒序遍历, 比如 6 -> 1 + 2 + 4(x), 6 -> 4 + 2(x) + 1
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    dfs(s);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}
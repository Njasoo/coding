#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 5;
int f[N], siz[N], r[N];
int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
bool same(int x, int y) { return leader(x) == leader(y); }
bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return 0;
    f[y] = x;
    siz[x] += siz[y];
    return 1;
} 
vector<int> p[N];
int dp[N][2];
void solve(int u) {
    for (auto v : p[u]) {
        dp[v][0] = max(dp[u][0], dp[u][1]);
        dp[v][1] = dp[u][0] + r[v];
    }
}
int size(int x) { return siz[leader(x)]; }
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        f[i] = i;
    }   
    for (int i = 1; i < n; i++) {
        int l, k;
        scanf("%d %d", &l, &k);
        p[l].push_back(k);
        merge(k, l);
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            root = i;
            break;
        }
    }
    cerr << " " << root << endl;
    solve(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
int f[N], siz[N];
int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return;
    f[y] = x;
    siz[x] += siz[y];
}
int size(int x) {
    return siz[leader(x)];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = 0;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            ans++;
            nums.push_back(size(i));
        }
    }
    sort(nums.rbegin(), nums.rend());
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << nums[i] << " \n"[i == ans - 1];
    }
    return 0;
}
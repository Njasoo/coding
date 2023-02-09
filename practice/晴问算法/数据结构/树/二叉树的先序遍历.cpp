#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 55;
int n;
struct node {
    int ls, rs;
} t[N];
int cnt = 0;
void dfs(int u) {
    if (u == -1) return;
    cnt++;
    cout << u;
    if (cnt != n) cout << " ";
    dfs(t[u].ls);
    dfs(t[u].rs);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> t[i].ls >> t[i].rs;
    }
    dfs(0);
    return 0;
}
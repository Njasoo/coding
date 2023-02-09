#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 55;
int n;
struct node {
    int ls, rs;
} t[N];
vector<int> ans;
void dfs(int u) {
    // if (u == -1) return;
    if (t[u].ls != -1) dfs(t[u].ls);
    if (u != -1) ans.push_back(u);
    if (t[u].rs != -1) dfs(t[u].rs);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> t[i].ls >> t[i].rs;
    }
    dfs(0);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}
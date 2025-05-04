#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e4 + 5, M = 105;
bool dp[N][M];
int v[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            if (j - v[i] >= 0) dp[i][j] = (dp[i + 1][j] || dp[i + 1][j - v[i]]);
            else dp[i][j] = dp[i + 1][j];
        }
    }
    if (!dp[1][m]) {
        cout << "No Solution\n";
        return 0;
    }
    int j = m;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (j >= v[i] && dp[i + 1][j - v[i]]) {
            ans.push_back(v[i]);
            j -= v[i];
        }
    }
    for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }
    return 0;
}
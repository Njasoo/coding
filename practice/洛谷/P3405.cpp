#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, string> match;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        u = u.substr(0, 2);
        if (match[v] == u) ans++;
        match[u] = v;
    }   
    cout << ans << '\n';
    return 0;
}
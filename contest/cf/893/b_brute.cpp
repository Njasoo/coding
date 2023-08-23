#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int p[N];
bool vis[N];

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    p[1] = 1, p[2] = 2, p[n + 1] = p[1];
    memset(vis, 0, sizeof(vis));
    vis[1] = vis[2] = 1;
    set<int> s;
    for (int i = 3; i <= n; i++) {
        s.insert(i);
    }
    for (int i = 3; i <= n; i++) {
        bool flag = 0;
        for (int j = p[i - 1]; j <= n; j += p[i - 1]) {
            if (!vis[j]) {
                vis[j] = 1;
                flag = 1;
                p[i] = j;
                s.erase(j);
                break;
            }
        }
        if (!flag) {
            p[i] = *s.begin();
            vis[*s.begin()] = 1;
            s.erase(s.begin());
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
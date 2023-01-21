#include <bits/stdc++.h>

using namespace std;

int k[205], vis[205];
int jump[2] = {1, -1};

struct node {
    int f, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }   
    queue<node> q;
    q.push({a, 0});
    vis[a] = 1;
    node u = q.front();
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u.f == b) {
            break;
        }
        for (int i = 0; i < 2; i++) {
            int dist = u.f + k[u.f] * jump[i];
            if (dist >= 1 && dist <= n && vis[dist] == 0) {
                vis[dist] = 1;
                q.push({dist, u.d + 1});
            }
        }
    }
    cout << (u.f == b ? u.d : -1) << '\n';
    return 0;
}
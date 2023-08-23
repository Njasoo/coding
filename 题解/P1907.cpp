#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1e3 + 5;
double _dr, _rr;
int n;
double x[N], y[N], dis[N];
bool isrr[N][N], vis[N];
vector<pair<int, double>> g[N];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<int, int>>> q;

double Dis(int i, int j) {
    double cnt = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    if (isrr[i][j]) return cnt * _rr;
    return cnt * _dr;
}

void dijkstra() {
    for (int i = 0; i <= n + 1; i++) {
        dis[i] = 1e9;
    }
    dis[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (d + w < dis[v]) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> _dr >> _rr;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int u, v;
    while (cin >> u >> v) {
        if (!u && !v) break;
        isrr[u][v] = 1;
        isrr[v][u] = 1;
    }
    cin >> x[0] >> y[0] >> x[n + 1] >> y[n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            double cnt = Dis(i, j);
            g[i].push_back({j, cnt});
            g[j].push_back({i, cnt});
        }
    }
    dijkstra();
    cout << fixed << setprecision(4) << dis[n + 1] << '\n';
    return 0;
}
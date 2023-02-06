#include <bits/stdc++.h>

using namespace std;

double ans = 0x3f3f3f3f, g_now_x = 0, g_now_y = 0, g_now_dis = 0;
int n, vis[20], path[20];

struct node {
    double x, y;
}m[20];

double dis(double &x1, double &y1, double &x2, double &y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void save() {
    double now_x = 0, now_y = 0;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dis(now_x, now_y, m[path[i]].x, m[path[i]].y);
        now_x = m[path[i]].x; now_y = m[path[i]].y;
    }
    ans = min(ans, sum);
}

void dfs(int k) {
    if (k > n) {
        save();
    }
    if (g_now_dis >= ans) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            path[k] = i;
            double temp_dis = dis(g_now_x, g_now_y, m[i].x, m[i].y);
            g_now_dis += temp_dis;
            double temp_x = g_now_x, temp_y = g_now_y;
            g_now_x = m[i].x; g_now_y = m[i].y;
            vis[i] = 1;
            dfs(k + 1);
            g_now_x = temp_x; g_now_y = temp_y;
            g_now_dis -= temp_dis;
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i].x >> m[i].y;
    }   
    dfs(1);
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}
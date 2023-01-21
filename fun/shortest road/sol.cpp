/**
 *    author:  Njaso
 *    created: 02.06.2022 23:39:30
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 25;
double g_x = 0, g_y = 0, _x = 0, _y = 0, ans = 0x3f3f3f3f, sum = 0;
int path[N], ans_path[N], n;
bool vis[N];

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct node {
  double x;
  double y;
}t[N];

void save() {
  double cnt = 0;
  double now_x = _x, now_y = _y;
  for (int i = 1; i <= n; i++) {
    cnt += dis(now_x, now_y, t[path[i]].x, t[path[i]].y);
    now_x = t[path[i]].x;
    now_y = t[path[i]].y;
  }
  if (cnt < ans) {
    ans = cnt;
    for (int i = 1; i <= n; i++) {
      ans_path[i] = path[i];
    }
  }
}

void dfs(int k) {
  if (sum > ans) {
    return;
  }
  if (k > n) {
    save();
  } else {
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        path[k] = i;
        double temp_sum = dis(g_x, g_y, t[i].x, t[i].y);
        double temp_x = g_x;
        double temp_y = g_y;
        g_x = t[i].x;
        g_y = t[i].y;
        sum += temp_sum;
        vis[i] = true;
        dfs(k + 1);
        sum -= temp_sum;
        g_x = temp_x;
        g_y = temp_y;
        vis[i] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> g_x >> g_y;
  _x = g_x;
  _y = g_y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i].x >> t[i].y;
  }
  dfs(1);
  cout << "(" << _x << ", " << _y << ")" << " --> ";
  for (int i = 1; i < n; i++) {
    cout << "(" << t[ans_path[i]].x << ", " << t[ans_path[i]].y << ")" << " --> ";
  }
  cout << "(" << t[ans_path[n]].x << ", " << t[ans_path[n]].y << ")" << '\n';
  cout << fixed << setprecision(5) << ans << '\n';
  return 0;
}
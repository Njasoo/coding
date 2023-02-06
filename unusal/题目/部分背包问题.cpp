#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
  int m, v;
}a[105];

bool cmp(node &x, node &y) {
  return x.v * y.m > y.v * x.m; // 按照性价比排序，是单位价值的不等式恒等变形
}

int main() {
  int n, t, c, i;
  double ans = 0;
  scanf("%d %d", &n, &t);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i].m, &a[i].v);
  }
  c = t; // 背包剩余承重量 == 总承重量
  sort(a, a + n, cmp);
  for (i = 0; i < n; i++) {
    if (c < a[i].m) break; // 背包承重量不足就直接跳出
    c -= a[i].m; // 先把性价比最高的金币全部拿走
    ans += a[i].v;
  }
  if (i < n) {
    ans += 1.0 * c / a[i].m * a[i].v; // 如果没有全部拿完，就看剩下能装多少就装多少
  }
  printf("%.2lf\n", ans);
  return 0;
}
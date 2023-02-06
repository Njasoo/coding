#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int p[N], t[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  cin >> p[1];
  for (int i = 2; i <= m; i++) {
    cin >> p[i];
    int s = min(p[i], p[i - 1]);
    int e = max(p[i], p[i - 1]);
    t[s]++;
    t[e]--;
  }
  long long sum = 0, ans = 0;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    sum += t[i];
    ans += min(sum * a, sum * b + c);
  }
  cout << ans << '\n';
  return 0;
}
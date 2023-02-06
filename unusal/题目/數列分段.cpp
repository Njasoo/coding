#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = (int) 1e6 + 5;
const ll MOD = (int) 1e6 + 7;
const ll INF = (int) 1e9;
int a[N];
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
// int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l = max(l, a[i]);
    r += a[i];
  }
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cnt = 0, s = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt + a[i] <= mid) {
        cnt += a[i];
      } else {
        cnt = a[i];
        s++;
      }
    }
    if (s >= m) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << l << '\n';
  return 0;
}
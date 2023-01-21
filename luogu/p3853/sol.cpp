#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int l, n, k;
  cin >> l >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int left = 0, right = (int) 1e9;
  int ans = 0;
  while (left <= right) {
    int mid = (left + right) >> 1;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] > mid) {
        cnt += (a[i + 1] - a[i]) / mid;
        if ((a[i + 1] - a[i]) % mid == 0) {
          --cnt;
        }
      }
      if (cnt > k) {
        break;
      }
    }
    if (cnt <= k) {
      right = mid - 1;
      ans = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
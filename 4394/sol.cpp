#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 5;
int cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int dist = 0, maxlen = 0;
  pair<int, int> ans;
  int l = 0, r = 0;
  while (l < n) {
    while (r < n && dist <= k) {
      if (++cnt[a[r]] == 1) dist++;
      if (dist == k + 1) break;
      r++;
    }
    if (r - l > maxlen) {
      maxlen = r - l;
      ans = {l + 1, r};
    }
    if (dist <= k) break;
    while (l < n && dist == k + 1) {
      if (--cnt[a[l]] == 0) dist--;
      if (dist == k) break;
      l++;
    }
  }
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}
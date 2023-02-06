#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  struct node {
    int val, pos;
  };
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  } 
  deque<node> q;
  for (int i = 1; i <= n; i++) {
    if (q.empty()) {
      q.push_back({a[i], i});
    }
    while (!q.empty() && a[i] > q.back().val) {
      q.pop_back();
    }
    q.push_back({a[i], i});
    if (i >= k) {
      cout << q.front().val << '\n';
      if (q.front().pos == i - k + 1) {
        q.pop_front();
      }
    }
  }
  return 0;
}
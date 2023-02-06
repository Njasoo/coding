#include <bits/stdc++.h>

using namespace std;

long long a[100001];
struct node {
  long long val, tag;
}t[400001];

void build(int id, int left, int right) {
  t[id].tag = 0;
  if (left == right) {
    t[id].val = a[left];
    return;
  }
  int mid = (left + right) >> 1;
  build(id << 1, left, mid);
  build(id << 1 | 1, mid + 1, right);
  t[id].val = t[id << 1].val + t[id << 1 | 1].val;
}

void push_down(int id) {
  t[id << 1].tag += t[id].tag;
  t[id << 1 | 1].tag += t[id].tag;
  t[id].tag = 0;
}

void update(int id, int left, int right, int s, int e, long long k) {
  if (e < left || s > right) {
    return;
  }
  if (s <= left && right <= e) {
    t[id].tag += k;
    return;        
  }
  push_down(id);
  int mid = (left + right) >> 1;
  update(id << 1, left, mid, s, e, k);
  update(id << 1 | 1, mid + 1, right, s, e, k);
  t[id].val = t[id << 1].val + t[id << 1].tag * (mid - left + 1) + t[id << 1 | 1].val + t[id << 1 | 1].tag * (right - mid);
}

long long query(int id, int left, int right, int s, int e) {
  if (e < left || s > right) {
    return 0;
  }
  if (s <= left && right <= e) {
    return t[id].val + t[id].tag * (right - left + 1);
  }
  push_down(id);
  int mid = (left + right) >> 1;
  long long res = query(id << 1, left, mid, s, e) + query(id << 1 | 1, mid + 1, right, s, e);
  t[id].val = t[id << 1].val + t[id << 1].tag * (mid - left + 1) + t[id << 1 | 1].val + t[id << 1 | 1].tag * (right - mid);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      long long k;
      cin >> x >> y >> k;
      update(1, 1, n, x, y, k);
    } else {
      int x, y;
      cin >> x >> y;
      cout << query(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}
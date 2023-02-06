#include <bits/stdc++.h>

using namespace std;

int a[2000005], q[2000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int head = 1, tail = 0;
  for (int i = 1; i <= n; i++) {
    if (head > tail) { // head > tail means queue is empty
      q[++tail] = i;
    }
    while (head <= tail && a[i] > a[q[tail]]) {
      --tail;
    }
    q[++tail] = i;
    if (i >= k) {
      cout << a[q[head]] << '\n';
      if (q[head] == i - k + 1) {
        ++head;
      }
    }
  }
  return 0;
}
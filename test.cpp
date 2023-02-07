#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      ans++;
    } else {
      ans--;
    }
  }
  return 0;
}
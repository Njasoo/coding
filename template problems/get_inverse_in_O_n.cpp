#include <bits/stdc++.h>

using namespace std;

int inv[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  inv[1] = 1;
  int n, p;
  cin >> n >> p;
  for (int i = 2; i <= n; i++) {
    inv[i] = -(p / i) * inv[p % i];
    inv[i] = (inv[i] % p + p) % p;
  }
  for (int i = 1; i <= n; i++) {
    cout << inv[i] << " \n"[i == n];
  }
  return 0;
}
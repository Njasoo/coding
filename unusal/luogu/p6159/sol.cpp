#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, p, k;
  cin >> n >> p >> k;
  cout << ((k % n) * (p % n) % n) << '\n';
  return 0;
}
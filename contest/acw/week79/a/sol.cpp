#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
    if (sum == n) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
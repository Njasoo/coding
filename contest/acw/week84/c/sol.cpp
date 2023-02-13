#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int goal = n * m - k;
  if (goal <= 0) {
    cout << 0 << '\n';
  } else {
    int case1 = goal / n * c + c * (goal % n != 0);
    int case2 = goal * d;
    int case3 = goal / n * c + d * (goal % n);
    cout << min({case1, case2, case3}) << '\n';
  }
  return 0;
}
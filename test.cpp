#include <bits/stdc++.h>
using namespace std;
#define debug(x) << cerr << #x << " " << x << endl;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> f[i][j];
      }
    }
  }
  return 0;
}

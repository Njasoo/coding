#include <bits/stdc++.h>
using namespace std;
#define debug(x) << cerr << #x << " " << x << endl;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string t = "ROYGBIV";
  for (int i = 0; i < n; i++) {
    cout << t[i % t.size()];
  }
  cout << '\n';  
  return 0;
}

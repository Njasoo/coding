#include <bits/stdc++.h>
using namespace std;
#define debug(x) << cerr << #x << " " << x << endl;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> cnt;
  string ans;
  int mx_fre = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    cnt[s]++;
    if (cnt[s] > mx_fre) {
      mx_fre = cnt[s];
      ans = s;
    }
  }  
  cout << ans << '\n';
  return 0;
}

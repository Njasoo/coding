/**
 *    author:  Njaso
 *    created: 03.07.2022 14:17:36
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, pair<int, int>> hs; // first: occurence of number, second: the position of the latest number
  map<int, bool> invalid;
  map<int, int> ans;
  int invalid_number = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (hs[a[i]].first == 1) {
      ans[a[i]] = i - hs[a[i]].second;
    } else if (hs[a[i]].first >= 2) {
      int temp = i - hs[a[i]].second;
      if (temp != ans[a[i]]) {
        if (invalid[a[i]] == false) {
          invalid[a[i]] = true;
          invalid_number += 1; // be carefully, don't calculate it more than one time
        }
      }
    }
    hs[a[i]].first += 1;
    hs[a[i]].second = i;
  }
  cout << hs.size() - invalid_number << '\n';
  for (auto &x : hs) {
    if (!invalid[x.first]) {
      cout << x.first << " " << ans[x.first] << '\n';
    }
  }
  return 0;
}
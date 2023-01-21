/**
 *    author:  Njaso
 *    created: 03.07.2022 15:38:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < k; i++) {
    a.push_back(n - i);
  }
  for (int i = 0; i < n - k; i++) {
    a.push_back(i + 1);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  return 0;
}
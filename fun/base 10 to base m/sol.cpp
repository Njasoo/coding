#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned long long n;
  int m;
  unordered_map<int, char> hash;
  for (int i = 10; i <= 31; i++) {
    hash.insert(make_pair(i, 'A' + i - 10));
  }
  cin >> n >> m;
  vector<char> ans;
  while (n >= 1) {
    if (n % m < 10) {
      ans.push_back((char) ((n % m) + '0'));
    } else {
      ans.push_back(hash[n % m]);
    }
    n /= m;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
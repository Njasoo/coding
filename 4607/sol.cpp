#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int j = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    while (j < (int) s.size() && dis < 26) {
      j++;
      if (++cnt[s[j]] == 1) dis++;
    }
    int len = 
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<char> v = {'a', 'o', 'y', 'e', 'u', 'i'};
  for (int i = 0; i < (int) s.size(); i++) {
    s[i] = (char) tolower(s[i]);
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (find(v.begin(), v.end(), s[i]) != v.end()) {
      s[i] = ' ';
    }
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != ' ') {
      cout << "." << s[i];
    }
  }
  cout << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  while (s.find("WUB") != string::npos) {
    s.replace(s.find("WUB"), 3, " ");
  }
  stringstream ss(s);
  string str;
  while (ss >> str) {
    cout << str << " ";
  }
  cout << '\n';
  return 0;
}
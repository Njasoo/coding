#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> hs;

string find(string x) {
  return x == hs[x] ? x : hs[x] = find(hs[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  char ch;
  string name, father;
  while (cin >> ch >> name) {
    if (ch == '$') {
      break;
    }
    if (hs[name] == "") {
      hs[name] = name;
    }
    if (ch == '#') {
      father = name;
    }
    if (ch == '+') {
      hs[name] = father;
    }
    if (ch == '?') {
      cout << name << " " << find(name) << '\n';
    }
  }
  return 0;
}
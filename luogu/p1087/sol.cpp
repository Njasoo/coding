#include <bits/stdc++.h>

using namespace std;

void post(string s) {
  if (s.size() == 0) {
    return;
  }
  char root;
  auto one = s.find('1');
  auto zero = s.find('0');
  if (zero == string::npos) {
    root = 'I';
  } else if (one == string::npos) {
    root = 'B';
  } else {
    root = 'F';
  }
  post(s.substr(0, s.size() / 2));
  post(s.substr(s.size() / 2, s.size() / 2));
  cout << root;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  post(s);
  cout << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void build(string in, string pre) {
  if (in.size() > 0) {
    char ch = pre[0];
    int k = in.find(ch);
    build(in.substr(0, k), pre.substr(1, k));
    build(in.substr(k + 1), pre.substr(k + 1));
    cout << ch;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string in, pre;
  cin >> in >> pre;
  build(in, pre); 
  return 0;
}
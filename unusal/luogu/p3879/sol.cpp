#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int cnt[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<string, vector<int>> hash;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    for (int j = 0; j < l; j++) {
      string s;
      cin >> s;
      hash[s].push_back(i + 1);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (int j = 0; j < (int) hash[s].size(); j++) {
      if (cnt[hash[s][j]] == 0) {
        cnt[hash[s][j]] = 1;
        cout << hash[s][j] << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
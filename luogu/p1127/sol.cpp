/**
 *    author:  Njaso
 *    created: 08.06.2022 19:49:06
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
string s[N], path[N], ans[N];
int n, len[N];
map<char, int> s1, s2;
bool vis[N], flag = false;

void dfs(int k) {
  if (flag) {
    return;
  }
  if (k > n) {
    flag = true;
    for (int i = 1; i <= n; i++) {
      ans[i] = path[i];
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && s[i][0] == path[k - 1][path[k - 1].size() - 1]) {
        vis[i] = true;
        path[k] = s[i];
        dfs(k + 1);
        vis[i] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    len[i] = s[i].size();
    s1[s[i][0]]++;
    s2[s[i][len[i] - 1]]++;
  }
  sort(s + 1, s + 1 + n);
  char b = ' ', e = ' ';
  for (char c = 'a'; c <= 'z'; c++) {
    if (s1[c] - s2[c] == 1) {
      b = c;
    }
    if (s2[c] - s1[c] == 1) {
      e = c;
    }
  }
  if (b == e) {
    vis[1] = true;
    path[1] = s[1];
    dfs(2);
  }
  int cnt = s2[e];
  for (int i = 1; i <= n; i++) {
    if (s[i][0] == b && (s[i][len[i] - 1] != e || cnt != 1)) {
      vis[i] = true;
      path[1] = s[i];
      dfs(2);
      break;
    }
  }
  if (!flag) {
    cout << "***" << '\n';
  } else {
    for (int i = 1; i < n; i++) {
      cout << ans[i] << ".";
    }
    cout << ans[n] << '\n';
  }
  return 0;
}
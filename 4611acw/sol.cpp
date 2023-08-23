#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 5;
long long a[N], cnt[N];
map<long long, int> hs[11];

long long read() {
  long long res = 0;
  bool flag = false;
  int ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = true;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return (flag ? -res : res);
}

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  long long n = read(), k = read();
  for (int i = 0; i < n; i++) {
    a[i] = read();
    long long temp = a[i];
    if (temp == 0) {
      cnt[i] = 1;
    } else {
      while (temp) {
        temp /= 10;
        cnt[i]++;
      }
    }
    hs[cnt[i]][a[i] % k]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long mod = a[i] % k;
    for (int j = 1; j <= 10; j++) {
      mod = mod * 10 % k;
      if (hs[j].find((k - mod) % k) != hs[j].end()) { // faster than hs[j][(k - mod) % k] ? I don't know why
        ans += hs[j][(k - mod) % k];
//        cerr << hs[j][(k - mod) % k] << endl;
        if (j == cnt[i] && a[i] % k == (k - mod) % k) ans--;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long read() {
  long long res = 0;
  int ch = getchar();
  bool flag = false;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = true;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return (flag ? -res : res);
}

const int N = (int) 2e5;
long long a[N], len[N];

int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  long long n = read(), k = read();
  map<pair<int, long long>, int> cnt;
  int maxlen = 0;
  for (int i = 0; i < n; i++) {
    a[i] = read();
    long long mod = a[i] % k;
    int temp_cnt = 0;
    long long temp = a[i];
    while (temp) {
      temp_cnt++;
      temp /= 10;
    }
    maxlen = max(maxlen, temp_cnt);
    len[i] = temp_cnt;
    cnt[{len[i], mod}]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long mod = a[i] % k;
    for (int j = 1; j <= maxlen; j++) {
      mod = mod * 10 % k;
      if (cnt.find({j, (k - mod) % k}) != cnt.end()) {
//        cerr << "cnt[{j, (k - mod) % k}]: " << cnt[{j, (k - mod) % k}] << endl;
        ans += cnt[{j, (k - mod) % k}];
        if (a[i] % k == (k - mod) % k && len[i] == j) ans--;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
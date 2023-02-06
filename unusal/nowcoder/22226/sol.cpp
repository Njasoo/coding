/**
 *    author:  Njaso
 *    created: 04.06.2022 22:07:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 1000005;
  vector<bool> prime(N, true);
  prime[1] = prime[0] = false;
  for (int i = 2; i <= (int) sqrt(N); i++) {
    for (int j = 2; j * i <= N; j++) {
      prime[i * j] = false;
    }
  }
  vector<int> a(N);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (prime[i]) {
      a[i] = ++cnt;
    } else {
      a[i] = cnt;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << a[n] << '\n';
  }
  return 0;
}
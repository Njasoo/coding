#include <bits/stdc++.h>

using namespace std;

// 求長度為k的最大子段和即可

long long sum[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    long long a;
    cin >> a;
    sum[i] = sum[i - 1] + a;
  } 
  long long mx = 0;
  for (int i = 1; i <= n - k; i++) {
    long long cnt = sum[i + k - 1] - sum[i - 1];
    if (cnt > mx) {
      mx = cnt;
    }
  }
  cout << sum[n - 1] - mx << '\n';
  return 0;
}
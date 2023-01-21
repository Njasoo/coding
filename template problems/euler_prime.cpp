#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int, bool> vis;
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = true;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size(); j++) {
      if (i * primes[j] > n) break;
      vis[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
  for (int i = 0; i < (int) primes.size(); i++) {
    cout << primes[i] << " ";
  }
  cout << "\n";
  return 0;
}
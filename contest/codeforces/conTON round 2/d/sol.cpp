#include <bits/stdc++.h>

using namespace std;

// lets construct an array, 0 * a0, 1 * a1, 2 * a2, ..., (n - 1) * an
// after operation1, the total sum of array has no changes. 
// the contribution is like this, (a - 1) - a - b + (b + 1) == 0
// after operation2, the total sum of the array has incresment of 1
// because (a - 1) - a - b + (b + 2) == 1
// so the array which has the biggest sum is the special array
// to calculate the frequency of operation 2, we just need to calculation the difference of the special array and other normal array

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      long long sum = 0;
      for (int j = 0; j < m; j++) {
        long long x;
        cin >> x;
        sum += x * j;
      }
      a[i] = sum;
    }
    int id = (int) (max_element(a.begin(), a.end()) - a.begin());
    cout << id + 1 << " " << a[id] - a[(id + 1) % n] << '\n';
  }
  return 0;
}
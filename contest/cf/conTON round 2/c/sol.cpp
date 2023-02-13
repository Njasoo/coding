#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  for (int test = 1; test <= tt; test++) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < m; i++) {
      b[i] = a[i] - a[i - 1] - 1; // number of houses that are not infected between one pair of neighbour
    }
    b[0] = n - a[m - 1] + a[0] - 1;
    int day = 0, ans = 0;
    sort(b.begin(), b.end());
    for (int i = m - 1; i >= 0; i--) {
      if (b[i] - 2 * day <= 0) {
        break;
      }
      b[i] -= 2 * day;
      if (b[i] <= 2) {
        day++;
        ans++;
      } else {
        day += 2; // i decided next two day, i will protect the house in the area, so time pass by 2, and only one will be infected
        ans += b[i] - 1;
      }
    }
    cout << n - ans << '\n';
  }
  return 0;
}
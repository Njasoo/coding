#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<string, array<long long, 3>> hs; // 0 : a, 1 : b, 2 : c
  int m, n;
  cin >> m >> n;
  int total_volumn = 21 - m;
  for (int i = 1; i <= n; i++) {
    long long a, b, c;
    string s;
    cin >> a >> b >> c >> s;
    hs[s][0] += a, hs[s][1] = b, hs[s][2] = c;
  }
  vector<long long> values;
  for (auto& obj : hs) {
    long long num = min(obj.second[0], obj.second[2]);
    long long value = obj.second[1] * num;
    values.push_back(value);
  }
  long long ans = 0;
  sort(values.rbegin(), values.rend());
  for (int i = 0; i < min((int) values.size(), total_volumn); i++) {
    ans += values[i];
  }
  cout << ans << '\n';
  return 0;
}
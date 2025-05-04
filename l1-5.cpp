#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

ll a[26];
int cnt[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
		ans += a[s[i] - 'a'];
	}
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << " \n"[i == 25];
	}
	cout << ans << "\n";
	return 0;
}

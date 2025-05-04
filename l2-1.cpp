#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

string s;
int p = 0;

void solve() {
	string res;
	while (p < s.size()) {
		if (s[p] == '(') {
			p++;
			solve();
		} else if (s[p] == ')') {
			cout << res << "\n";
			break;
		} else {
			res += s[p];
		}
		p++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	solve();
	return 0;
}

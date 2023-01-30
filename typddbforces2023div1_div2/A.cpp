#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n % 2) {
			cout << "-1\n";
		} else {
			cout << 1 << " " << n / 2 << '\n';
		}
	}	
	return 0;
}
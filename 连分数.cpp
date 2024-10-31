#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// x=a+1/x
	// x^2=ax+1
	// x^2-ax-1 = 0
	// (a+sqrt(a^2+4)) / 2
	int T;
	cin >> T;
	while (T--) {
		double a;
		cin >> a;
		cout << fixed << setprecision(20) << (a + sqrt(a * a + 4)) / 2 << '\n';
	}
	return 0;
}


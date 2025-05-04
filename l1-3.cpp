#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T, S, t;
	cin >> T >> S >> t;
	if (T > 35 && S == 1 && t >= 33) {
		cout << "Bu Tie\n";
		cout << T << "\n";
		return 0;
	}
	if (T > 35 && t >= 33 && S == 0) {
		cout << "Shi Nei\n";
		cout << T << "\n";
		return 0;
	}
	if (S == 1 && (T <= 35 || t < 33)) {
		cout << "Bu Re\n";
		cout << t << "\n";
		return 0;
	}
	if (S == 0 && (T <= 35 || t < 33)) {
		cout << "Shu Shi\n";
		cout << t << "\n";
		return 0;
	}
	return 0;
}

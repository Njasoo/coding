#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

struct Node {
	ll start, p, len;
};

void print(int start, int p, int len) {
	for (int i = start; i <= start + len - 1; i++) {
		cout << i << "^" << p;
		if (i != start + len - 1) {
			cout << "+";
		}
	}
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	Node ans = {-1, -1, -1};
	for (int i = 31; i >= 1; i--) {
		for (int j = 1; j <= 1; j++) {
			if (pow(j, i) > n) {
				break;
			}
			int k = j;
			ll cnt = 0;
			int len = 0;
			while (cnt < n) {
				cnt += pow(k, i);
//				db(k), db(i), db(pow(k, i)), el;
				k++;
				len++;
			}
			if (cnt == n) {
//				db(cnt), el;
				print(j, i, len);
			}
		}
	}
	cout << "Impossible for " << n << ".\n";
	return 0;
}

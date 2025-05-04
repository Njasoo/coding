#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

void solve(vector<int>& a, vector<int>& tmp1, vector<int>& tmp2) {
	for (int i = 1; i + tmp1.size() - 1 < a.size(); i++) {
		vector<int> tmp;
		for (int j = i; j < i + tmp1.size(); j++) {
			tmp.push_back(a[j]);
		}
		if (tmp1 == tmp) {
			a.erase(a.begin() + i, a.begin() + i + tmp1.size());
			a.insert(a.begin() + i, tmp2.begin(), tmp2.end());
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int L1;
			cin >> L1;
			vector<int> tmp1;
			for (int i = 1; i <= L1; i++) {
				int x;
				cin >> x;
				tmp1.push_back(x);
			}
			int L2;
			cin >> L2;
			vector<int> tmp2;
			for (int i = 1; i <= L2; i++) {
				int x;
				cin >> x;
				tmp2.push_back(x);
			}
			solve(a, tmp1, tmp2);
			for (int i = 1; i < a.size(); i++) {
//				cout << a[i] << " \n"[i == a.size() - 1];
			}
		} else if (op == 2) {
			for (int i = 1; i < a.size(); i++) {
				if ((a[i] + a[i + 1]) % 2 == 0) {
					a.insert(a.begin() + i + 1, (a[i] + a[i + 1]) / 2);
				}
			}
		} else {
			int l, r;
			cin >> l >> r;
			reverse(a.begin() + l, a.begin() + r + 1);
		}
	}
	for (int i = 1; i < a.size(); i++) {
		cout << a[i] << " \n"[i == a.size() - 1];
	}
	return 0;
}

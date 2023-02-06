#include <bits/stdc++.h>

using namespace std;

// 根節點維護當前x的值, 葉子結點t記錄第t次操作所乘的數, 若還沒有操作則是1, 除法也是1(除法用0表示);

int mod;
long long t[400001];

void build(int id, int left, int right) {
	t[id] = 1;
	if (left == right) {
		return;
	}
	int mid = (left + right) >> 1;
	build(id << 1, left, mid);
	build(id << 1 | 1, mid + 1, right);
}

void change(int id, int left, int right, int x, int val) {
	if (left == right) {
		t[id] = val == 0 ? 1 : val;
		return;
	}
	int mid = (left + right)  >> 1;
	if (x <= mid) {
		change(id << 1, left, mid, x, val);
	} else {
		change(id << 1 | 1, mid + 1, right, x, val);
	}
	t[id] = (t[id << 1] * t[id << 1 | 1]) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int q;
		cin >> q >> mod;
		build(1, 1, q);
		for (int i = 1; i <= q; i++) {
			int op;
			cin >> op;
			if (op == 1) {
				int m;
				cin >> m;
				change(1, 1, q, i, m);
				cout << t[1] % mod << '\n';
			} else {
				int pos;
				cin >> pos;
				change(1, 1, q, pos, 0);
				cout << t[1] % mod << '\n';
			}
		}
	}	
    return 0;
}
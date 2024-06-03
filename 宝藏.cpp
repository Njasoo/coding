#include <bits/stdc++.h>
using namespace std;

struct Matrix {
	int f[2][2];
	
	Matrix(int a, int b, int c, int d) {
		f[0][0] = a, f[0][1] = b, f[1][0] = c, f[1][1] = d;
	}
	
	bool operator<(const Matrix& rhs) const {
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int, Matrix>> q;
	int front = 0, tail = 1;
	for (int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		if (v == 1) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			Matrix A(a, b, c, d);
			q.push_back({front--, A});
		} else if (v == 2) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			Matrix B(a, b, c, d);
			q.push_back({tail++, B});
		} else {
			q.pop_back();
		}
	}
	return 0;
}


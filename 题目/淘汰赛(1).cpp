#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int n;
int value[260], winner[260];

void dfs(int x) {
	if (x >= (1 << n)) { // 遍历到叶子结点
		return;
	} else {
		dfs(2 * x); // 遍历左结点
		dfs(2 * x + 1); // 遍历右结点
		int l = value[2 * x], r = value[2 * x + 1];
		if (l > r) {
			value[x] = l; // 胜者的能力值
			winner[x] = winner[2 * x]; // 胜者的编号
		} else {
			value[x] = r;
			winner[x] = winner[2 * x + 1];
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		cin >> value[i + (1 << n)]; // 能力值（最后一层）
		winner[i + (1 << n)] = i + 1; // 编号
	}
	dfs(1);
	cout << (value[2] > value[3] ? winner[3] : winner[2]) << endl; // 亚军
#ifdef LOCAL
	cerr << "TIME ELAPSED: " << clock() << " ms" << endl;
#endif
	return 0;
}
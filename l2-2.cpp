#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

const int N = 5e4 + 5;
pair<int, int> t[N];
vector<int> pos[3];
struct Node {
	int x1, y1;
	int x2, y2;
	int x3, y3;
};
vector<Node> ans;

double slope(int x1, int y1, int x2, int y2) {
	return (1.0 * y2 - y1) / (1.0 * x2 - x1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].first >> t[i].second;
	}
	sort(t + 1, t + n + 1);
	int len = unique(t + 1, t + n + 1) - (t + 1);
	for (int i = 1; i <= len; i++) {
		pos[t[i].second].push_back(i);
	}
	map<pair<double, int>, vector<int>> mark;
	for (int p2 : pos[1]) {
		for (int p3 : pos[2]) {
			int x2 = t[p2].first;
			int y2 = t[p2].second;
			int x3 = t[p3].first;
			int y3 = t[p3].second;
			double k = slope(x2, y2, x3, y3);
			mark[{k, p2}].push_back(p3);
		}
	}
	for (int p1 : pos[0]) {
		for (int p2 : pos[1]) {
			int x1 = t[p1].first;
			int y1 = t[p1].second;
			int x2 = t[p2].first;
			int y2 = t[p2].second;
			double k = slope(x1, y1, x2, y2);
//			for (int p3 : pos[2]) {
//				int x3 = t[p3].first;
//				int y3 = t[p3].second;
//				double k2 = slope(x2, y2, x3, y3);
//				if (k2 == k) {
//					ans.push_back({x1, y1, x2, y2, x3, y3});
//				}
//			}
			for (int p3 : mark[{k, p2}]) {
				int x3 = t[p3].first;
				int y3 = t[p3].second;
				ans.push_back({x1, y1, x2, y2, x3, y3});
			}
		}
	}
	if (ans.size() == 0) {
		cout << "-1\n";
	} else {
		sort(ans.begin(), ans.end(), [&](Node i, Node j) {
			if (i.y2 == j.y2) {
				return i.x1 < j.x1;
			}
			return i.x2 < j.x2;
		});
		for (int i = 0; i < ans.size(); i++) {
			cout << "[" << ans[i].x1 << ", " << ans[i].y1 << "] ";
			cout << "[" << ans[i].x2 << ", " << ans[i].y2 << "] ";
			cout << "[" << ans[i].x3 << ", " << ans[i].y3 << "]";
			cout << "\n";
		}
	}
	return 0;
}

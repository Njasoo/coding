#include <bits/stdc++.h>

using namespace std;

void dfs(string in, string post) {
	if (in.size() > 0) {
		char ch = post.back();
		cout << ch;
		int k = in.find(ch);
		dfs(in.substr(0, k), post.substr(0, k));
		dfs(in.substr(k + 1), post.substr(k, post.size() - k - 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	dfs(a, b);
	cout << '\n';	
	return 0;
}
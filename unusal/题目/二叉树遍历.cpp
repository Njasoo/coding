#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 100005;

struct node {
	int left, right;
}t[N];

void PreOrder(int x) {
	cout << x << " ";
	if (t[x].left != 0) PreOrder(t[x].left);
	if (t[x].right != 0) PreOrder(t[x].right);
}

void InOrder(int x) {
	if (t[x].left != 0) InOrder(t[x].left);
	cout << x << " ";
	if (t[x].right != 0) InOrder(t[x].right);
}

void PostOrder(int x) {
	if (t[x].left != 0) InOrder(t[x].left);
	if (t[x].right != 0) InOrder(t[x].right);
	cout << x << " ";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].left >> t[i].right;
	}
	PreOrder(1);
	cout << '\n';
	InOrder(1);
	cout << '\n';
	PostOrder(1);
	cout << '\n';
	return 0;
}
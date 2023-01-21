#include <bits/stdc++.h>

using namespace std;

const int inf = 2147483647;

struct node {
	int value;
	int frequency;
	node* left;
	node* right;

	node(int x) : value(x), frequency(1), left(nullptr), right(nullptr) {}

	~node() {
		if (left != nullptr) {
			delete left;
			left = nullptr;
		}
		if (right != nullptr) {
			delete right;
			right = nullptr;
		}
	}

	int size() {
		int ans = 0;
		if (this->left != nullptr) {
			ans += this->left->size();
		}
		if (this->right != nullptr) {
			ans += this->right->size();
		}
		return ++ans;
	}
};

int ranking(int x, node* root) {
	if (root != nullptr) {
		if (x < root->value) {
			return ranking(x, root->left);
		}
		if (x > root->value) {
			int ans = 0;
			ans += ranking(x, root->right);
			ans += root->frequency;
			if (root->left != nullptr) {
				ans += root->left->size();
			}
			return ans;
		}
		int ans = root->frequency;
		if (root->left != nullptr) {
			ans += root->left->size();
		}
		return ans;
	}
	return 1;
}

int kth(int x, node* root) {
	if (root->left != nullptr) {
		if (x <= root->left->size()) {
			return kth(x, root->left);
		}
		if (x <= root->left->size() + root->frequency) {
			return root->value;
		}
		return kth(x - root->left->size() - root->frequency, root->right);
	} else {
		if (x <= root->frequency) {
			return root->value;
		}
		return kth(x - root->frequency, root->right);
	}
}

void insert(int x, node* root) {
	if (x < root->value) {
		if (root->left == nullptr) {
			auto left = new node(x);
			root->left = left;
		} else {
			insert(x, root->left);
		}
	} else if (x > root->value) {
		if (root->right == nullptr) {
			auto right = new node(x);
			root->right = right;
		} else {
			insert(x, root->right);
		}
	} else {
		root->frequency++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto root = new node(inf);
	int n;
	cin >> n;
	while (n--) {
		int opt, number;
		cin >> opt >> number;
		if (opt == 1) cout << ranking(number, root) << '\n';
		if (opt == 2) cout << kth(number, root) << '\n';
		if (opt == 3) cout << kth(ranking(number, root) - 1, root) << '\n';
		if (opt == 4) cout << kth(ranking(number + 1, root), root) << '\n';
		if (opt == 5) insert(number, root);
	}
	if (root != nullptr) {
		delete root;
		root = nullptr;
	}
	return 0;
}
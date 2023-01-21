#include <bits/stdc++.h>

using namespace std;

struct node {
    char val;
    int left, right;
}t[55];

void dfs(int x) {
    cout << t[x].val;
    if (t[x].left != 0) {
        dfs(t[x].left);
    }
    if (t[x].right != 0) {
        dfs(t[x].right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int root = 0;
    for (int i = 1; i <= n; i++) {
        char val, left, right;
        cin >> val >> left >> right;
        int id = val - 'a' + 1;
        int left_id = left - 'a' + 1;
        int right_id = right - 'a' + 1;
        t[id].val = val;
        if (left != '*') {
            t[id].left = left_id;
        }
        if (right != '*') {
            t[id].right = right_id;
        }
        if (i == 1) {
            root = id;
        }
    }   
    dfs(root);
    return 0;
}
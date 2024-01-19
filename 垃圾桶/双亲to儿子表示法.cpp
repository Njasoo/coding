#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
struct Node {
    int data;
    Node* next;
} *son[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < N; i++) {
        son[i] = new Node();
        son[i] = nullptr;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        int fa;
        cin >> fa;
        if (fa == -1) continue;
        Node* new_node = new Node();
        new_node->data = i;
        new_node->next = nullptr;
        if (son[fa] == nullptr) {
            son[fa] = new_node;
            continue;
        }
        auto p = son[fa];
        while (p->next) {
            p = p->next;
        }
        p->next = new_node;
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
        if (!son[i]) {
            cout << "-1\n";
            continue;
        }
        auto p = son[i];
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++) {
        auto p = son[i];
        while (p) {
            auto nex = p->next;
            delete p;
            p = nex;
        }
    }
    return 0;
}
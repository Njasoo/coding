#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

class Node {
public:
    int key;
    int value;
    Node *next;

    Node(int _key, int _value) : key(_key), value(_value), next(nullptr) {}

    ~Node() {
        if (this->next) {
            delete this->next;
            this->next = nullptr;
        }
    }
};

class HashDict {
public:
    vector<Node*> arr;
    int length;

    int hash(int _key) {
        cerr << (_key * _key * _key * 3 + _key * _key * 5 + _key * 7 + 11) % this->length << endl;
        return (_key * _key * _key * 3 + _key * _key * 5 + _key * 7 + 11) % this->length;
    }

    HashDict(int _length) : length(_length) {
        arr.resize(_length);
    }

    void insert(int _key, int _value) {
        int pos = hash(_key);
        auto new_node = new Node(_key, _value);
        arr[pos]->next = new_node;
    }

    void search(int _key) {
        int pos = hash(_key);
        cerr << "pos = " << pos << endl;
        auto p = arr[pos];
        if (p == nullptr) cerr << "NULL" << endl;
        while (p) {
            cout << "[" << p->key << "]" << ":" << "[" << p->value << "]";
            if (p->next) {
                cout << "->";
            }
            p = p->next;
        }
        cout << endl;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l;
    cin >> l; // 初始长度
    HashDict KMH(l);
    KMH.insert(1, 2);
    cout << KMH.arr[KMH.hash(1)]->value;
    KMH.search(1);
    return 0;
}
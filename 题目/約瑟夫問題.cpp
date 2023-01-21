#include <bits/stdc++.h>

using namespace std;

int v[105];
int back = 0;

void push_back(int x) {
    v[++back] = x;
}

void insert(int p, int x) {
    for (int i = back; i >= p; i--) {
        v[i + 1] = v[i];
    }
    v[p] = x;
}

void erase(int p) {
    for (int i = p + 1; i <= back; i++) {
        v[i - 1] = v[i];
    }
    --back;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        push_back(i);
    }  
    int index = 1;
    while (back) {
        index = ((index + m - 1) - 1) % back + 1;
        cout << v[index] << " ";
        erase(index);
    }
    cout << '\n';
    return 0;
}
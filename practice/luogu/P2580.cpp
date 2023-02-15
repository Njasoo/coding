#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 5e5 + 5;
int idx;
int tr[N][26];
bool exist[N], vis[N];
void insert(string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int to = s[i] - 'a';
        if (!tr[p][to]) tr[p][to] = ++idx;
        p = tr[p][to];
    }
    exist[p] = 1;
}
int query(string &s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int to = s[i] - 'a';
        if (!tr[p][to]) return 0;
        p = tr[p][to];
    }
    if (!exist[p]) return 0;
    if (!vis[p]) {
        vis[p] = 1;
        return 1;
    } else {
        return 2;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int flag = query(s);
        if (flag == 0) {
            cout << "WRONG\n";
        } else if (flag == 1) {
            cout << "OK\n";
        } else {
            cout << "REPEAT\n";
        }
    }
    return 0;
}
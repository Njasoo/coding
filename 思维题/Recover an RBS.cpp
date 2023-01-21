#include <bits/stdc++.h>

using namespace std;

/*
一个RBS序列就是有一个变量cnt=0, 遇到(时+1, 遇到)-1, 中途cnt不能<0, 而且遍历完整个序列后, cnt=0
所以最安全地构造一个RBS的方法就是先填满一半的(, 再填满一半的)
然后互换最右边的括号和最左边的括号(用问号填的那些), 检查是不是RBS
*/

bool check(string s) {
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt < 0) {
            return false;
        }
    }
    return cnt == 0;
}

void solve() {
    string s;
    cin >> s;
    int op = s.size() / 2;
    int cl = s.size() / 2;
    vector<int> pos;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '?') {
            pos.push_back(i);
        }
        if (s[i] == '(') op--;
        if (s[i] == ')') cl--;
    }
    // 这时候的op表示还剩下多少个开括号需要填补
    for (int i = 0; i < (int) pos.size(); i++) {
        if (i < op) {
            s[pos[i]] = '(';
        } else {
            s[pos[i]] = ')';
        }
    }
    int ok = 1;
    if (op > 0 && cl > 0) {
        swap(s[pos[op - 1]], s[pos[op]]); // 最右边的开括号和最左边的闭括号互换
        if (check(s)) {
            ok = 0;
        }
    }
    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// 前面有一个井号, 就填充一个右括号, 最后一个井号补上全部

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int cnt_left = 0, cnt = 0, cnt_right = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt_left++;
        if (s[i] == '#') cnt++;
        if (s[i] == ')') cnt_right++;
        flag = cnt_left >= cnt_right;
    }
    int diff = cnt_left - cnt_right;
    cnt_left = 0, cnt_right = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt_left++;
        if (s[i] == ')' || s[i] == '#') cnt_right++;
        if (cnt_left < cnt_right) flag = false;
    }
    if (!flag) {
        cerr << "hi1" << endl;
        cout << "-1\n";
        return 0;
    }
    if (diff < cnt) {
        cerr << "hi2" << endl;
        cout << "-1\n";
        return 0;
    }
    int last_sharp;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '#') {
            last_sharp = i;
            break;
        }
    }
    auto check = [](string str) -> bool { // 反括号序列
        int n = str.size();
        int cnt_left = 0, cnt_right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == ')') cnt_right++;
            if (str[i] == '(') cnt_left++;
            if (cnt_right < cnt_left) return false;
        }
        return true;
    };
    if (!check(s.substr(last_sharp + 1))) {
        cerr << "hi3" << endl;
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') continue;
        if (i == last_sharp) {
            cout << diff - cnt + 1 << '\n';
        } else {
            cout << "1\n";
        }
    }
    return 0;
}
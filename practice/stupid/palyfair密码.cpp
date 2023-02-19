#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> f(5, vector<char>(5));
    vector<bool> vis(26);
    string s;
    cin >> s;
    string code;
    cin >> code;
    for (int i = 0; i < s.size(); i++) {
        f[i / 5][i % 5] = s[i];
        vis[s[i] - 'a'] = true;
    }
    for (int i = s.size(); i < 25; i++) {
        for (int j = 0; j < 26; j++) {
            if (!vis[j]) {
                vis[j] = true;
                f[i / 5][i % 5] = (char)j + 'a';
                break;
            }
        }
    }
    auto match = [&](char a, char b) -> pair<int, int> {
        pair<int, int> res;
        pair<int, int> posa = {-1, -1}, posb = {-1, -1};
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (f[i][j] == a) {
                    posa = {i, j};
                }
                if (f[i][j] == b) {
                    posb = {i, j};
                }
            }
        }
        if (posa.first == -1 || posb.first == -1) return {'F', 'U'};
        if (posa.first == posb.first || posa.second == posb.second) {
            return {b, a};
        }
        res = {f[posa.first][posb.second], f[posb.first][posa.second]};
        return res;
    };
    for (int i = 0; i < code.size(); i += 2) {
        pair<char, char> new_chs = match(code[i], code[i + 1]);
        if (new_chs.first == 'F' && new_chs.second == 'U') {
            continue;
        }
        code[i] = new_chs.first, code[i + 1] = new_chs.second;
    }
    cout << code << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define db(x) std::cerr << #x << " = " << (x) << std::endl
int main() {
    std::ios::sync_with_stdio(true);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<std::pair<int, int>, bool> vis;
    vis[{0, 0}] = true;
    int nowx = 0, nowy = 0;
    bool flag = false;
    for (char c : s) {
        if (c == 'R') nowx++;
        if (c == 'L') nowx--;
        if (c == 'U') nowy++;
        if (c == 'D') nowy--;
        if (vis[{nowx, nowy}]) {
            flag = true;
            break;
        } else {
            vis[{nowx, nowy}] = true;
        }
    }   
    std::cout << (flag ? "Yes" : "No") << '\n';
    return 0;
}
#include <bits/stdc++.h>

const int N = 1e4 + 5;
bool tag[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int y1;
        std::cin >> y1;
        for (int i = 0; i <= 9999; i++) {
            tag[i] = false;
        }
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int y;
            std::cin >> y;
            tag[y] = true;
        }
        int y2;
        std::cin >> y2;
        int id = 0;
        for (int i = y1; i <= 9999; i++) {
            if (tag[i] == 0) id++;
            if (i == y2) {
                std::cout << id << "\n";
                break;
            }
        }
    }   
    return 0;
}
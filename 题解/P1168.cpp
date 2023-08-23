#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<int>> min;
    std::priority_queue<int> max;

    int a;
    std::cin >> a;
    std::cout << a << "\n";
    min.push(a);

    for (int i = 1; i < n; i++) {
        std::cin >> a;
        if (a < min.top()) max.push(a);
        else min.push(a);
        while (llabs(min.size() - max.size()) > 1) {
            if (min.size() > max.size()) {
                max.push(min.top());
                min.pop();
            } else {
                min.push(max.top());
                max.pop();
            }
        }
        if (i % 2 == 0) {
            if (min.size() > max.size()) {
                std::cout << min.top() << "\n";
            } else {
                std::cout << max.top() << "\n";
            }
        }
    }
    
    return 0;
}
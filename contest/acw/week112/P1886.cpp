#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::deque<int> q, p;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.back() <= a[i]) q.pop_back();
    }

    return 0;
}
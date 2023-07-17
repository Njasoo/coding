#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    const int INF = 1E9;
    std::vector<int> a(n + 1, INF);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    bool flag = false;
    std::pair<int, int> ans;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            // std::cerr << "i = " << i << std::endl;
            int j = i + 1;
            while (j < n && a[j] < a[j - 1]) {
                j++;
            }
            reverse(a.begin() + i, a.begin() + j);
            flag = true;
            ans = {i + 1, j};
            break;
        }
    }

    if (!flag || !is_sorted(a.begin(), a.end())) {
        std::cout << "0 0\n";
    } else {
        std::cout << ans.first << " " << ans.second << '\n';
    }
    
    return 0;
}
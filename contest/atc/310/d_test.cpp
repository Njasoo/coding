#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, T, M;
    std::cin >> N >> T >> M;
    
    std::vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        std::cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    
    std::vector<int> c(N);
    
    int ans = 0;
    auto dfs = [&](auto self, int x, int y) -> void {
        if (x == N) {
            if (y != T) {
                return;
            }
            bool ok = true;
            for (int i = 0; i < M; i++) {
                if (c[A[i]] == c[B[i]]) {
                    ok = false;
                }
            }
            ans += ok;
            return;
        }
        for (int i = 0; i <= y; i++) {
            c[x] = i;
            self(self, x + 1, std::max(y, i + 1));
        }
    };
    dfs(dfs, 0, 0);
    std::cout << ans << "\n";
    
    return 0;
}

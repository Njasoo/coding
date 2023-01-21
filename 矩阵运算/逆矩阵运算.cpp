#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iomanip>

int fac(int n);
long double calculate_determinant(const std::vector<std::vector<long double>>& D);
int reverse_number(const std::vector<int>& p);
std::vector<std::vector<long double>> adjugate_matrix(const std::vector<std::vector<long double>>& D);
void solve();

int reverse_number(const std::vector<int>& p) {
    int res = 0;
    int n = (int) p.size() - 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[j] < p[i]) {
                res++;
            }
        }
    }
    return res;
}

int fac(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long double calculate_determinant(const std::vector<std::vector<long double>>& D) {
    int n = (int) D.size() - 1;
    std::vector<int> order(n + 1);
    for (int i = 1; i <= n; i++) {
        order[i] = i;
    }
    int k = fac(n);
    long double ans = 0.0;
    for (int i = 1; i <= k; i++) {
        std::next_permutation(order.begin() + 1, order.end());
        long double cnt = 1.0;
        for (int j = 1; j <= n; j++) {
            cnt *= D[j][order[j]];
        }
        if (reverse_number(order) % 2 == 1) {
            cnt *= -1;
        }
        ans += cnt;
    }
    return ans;
}

std::vector<std::vector<long double>> cofactor(int x, int y, const std::vector<std::vector<long double>>& D) {
    int n = (int) D.size() - 1;
    std::vector<std::vector<long double>> ans(n, std::vector<long double>(n));
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            ans[i][j] = D[i][j];
        }
    }
    for (int i = 1; i < x; i++) {
        for (int j = y + 1; j <= n; j++) {
            ans[i][j - 1] = D[i][j];
        }
    }
    for (int i = x + 1; i <= n; i++) {
        for (int j = 1; j < y; j++) {
            ans[i - 1][j] = D[i][j];
        }
    }
    for (int i = x + 1; i <= n; i++) {
        for (int j = y + 1; j <= n; j++) {
            ans[i - 1][j - 1] = D[i][j];
        }
    }
    return ans;
}

std::vector<std::vector<long double>> adjugate_matrix(const std::vector<std::vector<long double>>& D) {
    int n = (int) D.size() - 1;
    std::vector<std::vector<long double>> temp(n + 1, std::vector<long double>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::vector<std::vector<long double>> cofactor_of_ij = cofactor(i, j, D);
            temp[i][j] = calculate_determinant(cofactor_of_ij);
            if ((i + j) % 2 == 1) {
                temp[i][j] = -temp[i][j];
            }
        }
    }
    std::vector<std::vector<long double>> ans(n + 1, std::vector<long double>(n + 1));
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            ans[i][j] = temp[j][i];
        }
    }
    return ans;
}

std::vector<std::vector<long double>> constant_X_matrix(const std::vector<std::vector<long double>>& A, long double k) {
    int n = (int) A.size() - 1;
    std::vector<std::vector<long double>> ans(n + 1, std::vector<long double>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] = A[i][j] * k;
        }
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<long double>> A(n + 1, std::vector<long double>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> A[i][j];
        }
    }
    std::vector<std::vector<long double>> ans = constant_X_matrix(adjugate_matrix(A), 1.0 / calculate_determinant(A));
    std::cout << std::fixed << std::setprecision(3);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << '\t' << ans[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    solve();
    std::cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << std::endl;
    return 0;
}
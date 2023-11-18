#include <cmath>
#include <iostream>

using namespace std;

const double pi = 3.14159265358979;

bool check(int mid, double d) {
    double r = sqrt(100.0 / pi * mid);
    return r >= d;
}

int main() {
    int n;
    scanf("%d", &n);
    double x, y;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &x, &y);
        int l = 1, r = 1e9;
        int ans = -1;
        double d = sqrt(x * x + y * y);
        // cerr << "d = " << d << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, d)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        double R = sqrt(100.0 / pi * ans);
        // cerr << "R = " << R << endl;
        printf("Property %d: This property will begin eroding in year %d.\n",
               ++cnt, ans);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}